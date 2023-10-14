#include "qwcalsoftware.h"
#include "qwparainput.h"
#include "qwparainput2.h"
#include "qwparainput3.h"
#include "qwparainput4.h"
#include "qwparainput5.h"
#include "ui_qwcalsoftware.h"

QWCalSoftware::QWCalSoftware(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWCalSoftware)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized); //设置默认全屏
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect rect = screen->geometry();
    screenW = rect.width();
    screenH = rect.height(); //获取用户屏幕尺寸
//    std::cout<<1000/screenW<<"######"<<screenH<<std::endl;
    iniUI();

    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(20, 90, 450, 330);
    label1 = new QLabel(this);
    label1->setAlignment(Qt::AlignCenter);
    label1->setGeometry(520*screenW/960, 90*screenH/540, 450*screenW/960, 330*screenH/540); //提前设置label(很重要)
    //QGridLayout *layout = new QGridLayout(this);
    //layout->addWidget(ui->graphicsView,0,0,1,2);
    //layout->addWidget(ui->graphicsView_2,1,0);
    //layout->addWidget(ui->graphicsView_3,1,1);
    //ui->centralwidget->setLayout(layout);
}

QWCalSoftware::~QWCalSoftware()
{
    delete ui;
}

void QWCalSoftware::iniUI()
{
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前荷载步：");
    ui->statusBar->addWidget(fLabCurFile); //添加状态栏label

    sortComboBox = new QComboBox;
    sortComboBox->setObjectName("combobox");
    sortComboBox->addItem("模型1：巴西劈裂试验");
    sortComboBox->addItem("模型2：单边缺口试件裂纹扩展试验");
    sortComboBox->addItem("模型3：中心缺口试件裂纹扩展试验");
    sortComboBox->addItem("模型4：L板断裂试验");
    sortComboBox->addItem("模型5：xxx");
    ui->toolBar->addWidget(sortComboBox); //添加combobox项
}

void QWCalSoftware::calGMPPD()
{
//    double start = GetTickCount64();

    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paraL[8];
    //y方向点个数
//    const int ndivy = ndivx;
    const int ndivy = paraL[9];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx;
    //总荷载步数
    const int nt = paraL[7];
//    const int nt = 100;
    // 速度边界
    double vbd = paraL[10];
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = 0.5;
    l = length;
    //试件宽度
    double width = 0.5;
    w = width;
    //初始裂纹长度
//    double cracklength = 0.5 * length;
    double cracklength = paraL[5];
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
//    double thick = min(dx, dy);
    double thick = paraL[6];
    //邻域半径
    double delta = 3.015 * sqrt(pow(dx, 2) + pow(dy, 2));  //固定
    //邻域半径的一半，用于计算校正系数
    double radij = 0.5 * delta;
    //物质点面积
    double area = dx * dx;
    //物质点体积
    double vol = area * thick;
    // 材料密度
//    double rho = 8000.0;
    double rho = paraL[2];
    //弹性模量
//    double emod = 192.0e9;
    double emod = paraL[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
//    double pratio = 0.3;
    double pratio = paraL[1];
    // 体积模量
    double kmod = emod / (2.0 * (1 - pratio));
    // 虚拟键参数
    double bc = 6 * emod / ((1.0 - pratio) * pi * thick * pow(delta, 3));
    // 临界拉伸率
    double s0 = 0.01; // sqrt(5.0 * G0 / (9.0 * kmod * delta));
    //时间步长
    double dt = 0.8 * sqrt(2.0 * rho * dx / (pi * pow(delta, 2) * dx * bc));
    // 提前施加的荷载，用于计算表面校正系数
    double sedload = (9.0 / 16.0) * emod * 1e-6;

    //物质点坐标生成
    //声明整体散点坐标矩阵
    Eigen::MatrixXd coord = Eigen::MatrixXd::Zero(totnode, 2);
    //确定内部点坐标
    int nnum = 0;
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= ndivy; j = j + 1)
        {
            double coordx = (-1.0 * length / 2.0) + (dx / 2.0) + (i - 1) * dx;
            double coordy = (-1.0 * width / 2.0) + (dx / 2.0) + (j - 1) * dx;
            coord(nnum, 0) = coordx;
            coord(nnum, 1) = coordy;
            nnum = nnum + 1;
        }
    }
    //内部点的编号结束点
    int totint = nnum - 1;
    //确定顶部边界点坐标

    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx;
            coord(nnum, 1) = 1.0 / 2.0 * width + dx / 2.0 + (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //顶部边界点编号的结束点
    int totbottom1 = nnum - 1;
    //确定底部边界点坐标
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx;
            coord(nnum, 1) = -1.0 / 2.0 * width - dx / 2.0 - (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //加载端边界点编号的结束点
    int totup = nnum - 1;
    std::cout << "物质点生成完毕！" << std::endl;

    //确定每一个物质点邻域内的邻域粒子
    Eigen::VectorXi numfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi pointfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi nodefam = Eigen::VectorXi::Zero(maxfam * totnode);

    for (int i = 0; i < totnode; i = i + 1)
    {
        if (i == 0)
        {
            pointfam(i) = 0;
        }
        else
        {
            pointfam(i) = pointfam(i - 1) + numfam(i - 1);
        }
        for (int j = 0; j < totnode; j = j + 1)
        {
            double idist = sqrt(pow(coord(j, 0) - coord(i, 0), 2) + pow(coord(j, 1) - coord(i, 1), 2));

            if (i != j)
            {
                if (idist < delta + dx * 1e-8)
                {
                    numfam(i) = numfam(i) + 1;
                    nodefam(pointfam(i) + numfam(i) - 1) = j;
                }

            }
        }
    }
    std::cout << "邻域粒子信息计算完毕！" << std::endl;

    //计算表面校正系数
    Eigen::MatrixXd predisp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd fncst = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd stendens = Eigen::MatrixXd::Zero(totnode, 2);

    // x 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.001 * coord(i, 0);
        predisp(i, 1) = 0.0;
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 0) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j);
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij + (predisp.row(famj) - predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 0) = stendens(i, 0) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij, 2) * xij * vol * fac;
        }
        fncst(i, 0) = sedload / stendens(i, 0);

    }

    // y 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.0;
        predisp(i, 1) = 0.001 * coord(i, 1);
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 1) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j);
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij + (predisp.row(famj) - predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 1) = stendens(i, 1) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij, 2) * xij * vol * fac;
        }
        fncst(i, 1) = sedload / stendens(i, 1);
    }

    //初始化键是否断裂的矩阵，0表示键断裂，1表示键完整
    Eigen::SparseMatrix<int> breakbond(totnode, totnode);
    for (int i = 0; i < totnode; i = i + 1)
    {
        for (int j = 0; j < numfam(i); j = j + 1)
        {
            int famj = nodefam(pointfam(i) + j);

            if (((abs(coord(famj, 0)) < 0.5 * cracklength) || (abs(coord(i, 0)) < 0.5 * cracklength)) && coord(famj, 1) * coord(i, 1) < 0)
            {
                breakbond.coeffRef(i, famj) = 0;
            }
            else
            {
                breakbond.coeffRef(i, famj) = 1;
            }
        }
    }

    //提前声明的变量
    //初始化物质点的位移和速度矩阵
    Eigen::MatrixXd disp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd vel = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点所受的体力和键力矩阵
    Eigen::MatrixXd bodyforce = Eigen::MatrixXd::Zero(1, 2);
    bodyforce(0, 0) = 0;
    bodyforce(0, 1) = 0;
    Eigen::MatrixXd bondforce = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点损伤度的矩阵
    Eigen::VectorXd damage = Eigen::VectorXd::Zero(totnode);

    std::cout << "参数设置完毕！" << std::endl;

        //开始施加荷载步
        std::cout << "计算开始！" << std::endl;
        for (int tt = 1; tt <= nt; tt = tt + 1)
    {
        std::cout << "第 " << tt << " 步" << std::endl;

            // 施加边界：
            for (int i = (totint + 1); i <= totbottom1; i++)
        {
            vel(i, 1) = vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = (totbottom1 + 1); i <= totup; i++)
        {
            vel(i, 1) = -vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = 0; i < totnode; i++)
        {
            Eigen::MatrixXd forcei = Eigen::MatrixXd::Zero(1, 2);
            double breakindex = 0;

            for (int j = 0; j < numfam(i); j++)
            {
                int famj = nodefam(pointfam(i) + j);
                //计算键力
                Eigen::MatrixXd posij = (coord.row(famj) - coord.row(i));
                Eigen::MatrixXd curposij = posij + (disp.row(famj) - disp.row(i));
                double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
                double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
                double fac;
                if (xij < (delta - radij))
                {
                    fac = 1.0;
                }
                else if (xij < (delta + radij))
                {
                    fac = (delta + radij - xij) / (2 * radij);
                }
                else
                {
                    fac = 0.0;
                }
                double theta;
                if (abs(coord(famj, 1) - coord(i, 1)) <= 1e-12)
                {
                    theta = 0.0;
                }
                else if (abs(coord(famj, 0) - coord(i, 0)) <= 1e-12)
                {
                    theta = pi / 2.0;
                }
                else
                {
                    theta = atan((coord(famj, 1) - coord(i, 1)) / (coord(famj, 0) - coord(i, 0)));
                }
                double scx = (fncst(i, 0) + fncst(famj, 0)) / 2.0;
                double scy = (fncst(i, 1) + fncst(famj, 1)) / 2.0;
                double scr = 1 / (pow(cos(theta) / scx, 2) + pow(sin(theta) / scy, 2));
                scr = sqrt(scr);
                double tempindx = breakbond.coeffRef(i, famj);
                forcei = forcei + tempindx * (bc * (eta_xij / xij - 1)) * (vol * scr * fac) * (curposij / eta_xij);
                //计算物质点的损伤值
                double s = (eta_xij - xij) / xij;
                if (s > s0)
                {
                    breakbond.coeffRef(i, famj) = 0;
                    breakindex = breakindex + 1;
                }
            }
            bondforce(i, 0) = forcei(0, 0) + bodyforce(0, 0);
            bondforce(i, 1) = forcei(0, 1) + bodyforce(0, 1);
            damage(i) = breakindex / numfam(i);
        }

        for (int i = 0; i < totnode; i++)
        {
            //更新速度和位移
            if ((i > totint && i <= totbottom1) || (i > totbottom1 && i <= totup))
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
            }
            else
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                vel(i, 1) = vel(i, 1) + (dt / rho) * bondforce(i, 1);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
                disp(i, 1) = disp(i, 1) + dt * vel(i, 1);
            }
        }

        //后处理输出到paraview
        std::string filename = "D:\\result\\GMPPD_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename);
        outfile << "# vtk DataFile Version 3.0" << std::endl;
        outfile << "L_shape_plate_crack" << std::endl;
        outfile << "ASCII" << std::endl;
        outfile << "DATASET UNSTRUCTURED_GRID" << std::endl;
        outfile << std::endl;
        outfile << "POINTS  " << (totup + 1) << "  double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i, 0) + coord(i, 0) << std::setw(20) << disp(i, 1) + coord(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile << std::endl;
        outfile << "CELLS  " << (totup + 1) << "  " << 2 * (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << 1 << std::setw(20) << i << std::endl;
        }
        outfile << std::endl;
        outfile << "CELL_TYPES  " << (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << 1 << std::endl;
        }
        outfile << std::endl;
        outfile << "POINT_DATA  " << (totup + 1) << std::endl;
        outfile << "SCALARS dmg double 1" << std::endl;
        outfile << "LOOKUP_TABLE default" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << damage(i) << std::endl;
        }
        outfile << "VECTORS disp double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i, 0) << std::setw(20) << disp(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile.close();
        //后处理结束
    }
//    double  end = GetTickCount64();
    fLabCurFile->setText("当前项目：已计算完毕");

    return;
}

void QWCalSoftware::calEdgeDmg()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paraL[8];
    //y方向点个数
    const int ndivy = paraL[9];
//    const int ndivy = ndivx;
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    //总荷载步数
    const int nt = paraL[7];
//    const int nt = 100;
    // 速度边界
    double vbd = paraL[10];
//    double vbd = 30;
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paraL[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paraL[4];
//    double width = 0.5;
    w = width;
    //初始裂纹长度
    double cracklength = paraL[6];
//    double cracklength = 0.5 * length;
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
    double thick = paraL[5];
//    double thick = min(dx,dy);
    //邻域半径
    double delta = 3.015 * sqrt(pow(dx, 2)+ pow(dy, 2));
    //邻域半径的一半，用于计算校正系数
    double radij = 0.5 * delta;
    //物质点面积
    double area = dx * dx;
    //物质点体积
    double vol = area * thick;
    // 材料密度
    //    double rho = 8000.0;
    double rho = paraL[2];
    //弹性模量
    //    double emod = 192.0e9;
    double emod = paraL[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
    //    double pratio = 0.3;
    double pratio = paraL[1];
    // 体积模量
    double kmod = emod / (2.0 * (1 - pratio));
    // 虚拟键参数
    double bc = 6 * emod / ((1.0 - pratio) * pi * thick * pow(delta, 3));
    // 临界拉伸率
    double s0 = 0.01; // sqrt(5.0 * G0 / (9.0 * kmod * delta));
    //时间步长
    double dt = 0.8 * sqrt(2.0 * rho * dx / ( pi * pow(delta, 2) * dx * bc) );
    // 提前施加的荷载，用于计算表面校正系数
    double sedload = (9.0/16.0) * emod * 1e-6;

    //物质点坐标生成
    //声明整体散点坐标矩阵
    Eigen::MatrixXd coord = Eigen::MatrixXd::Zero(totnode, 2);
    //确定内部点坐标
    int nnum = 0;
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= ndivy; j = j + 1)
        {
            double coordx = (-1.0 * length / 2.0) + (dx / 2.0) + (i - 1) * dx;
            double coordy = (-1.0 * width / 2.0) + (dx / 2.0) + (j - 1) * dx;
            coord(nnum, 0) = coordx;
            coord(nnum, 1) = coordy;
            nnum = nnum + 1;
        }
    }
    //内部点的编号结束点
    int totint = nnum - 1;
    //确定顶部边界点坐标

    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx ;
            coord(nnum, 1) = 1.0 / 2.0 * width + dx / 2.0 + (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //顶部边界点编号的结束点
    int totbottom1 = nnum - 1;
    //确定底部边界点坐标
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx ;
            coord(nnum, 1) = -1.0 / 2.0 * width - dx / 2.0 - (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //加载端边界点编号的结束点
    int totup = nnum - 1;
    std::cout << "物质点生成完毕！" << std::endl;

    //确定每一个物质点邻域内的邻域粒子
    Eigen::VectorXi numfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi pointfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi nodefam = Eigen::VectorXi::Zero(maxfam * totnode);

    for (int i = 0; i < totnode; i = i + 1)
    {
        if (i == 0)
        {
            pointfam(i) = 0;
        }
        else
        {
            pointfam(i) = pointfam(i - 1) + numfam(i - 1);
        }
        for (int j = 0; j < totnode; j = j + 1)
        {
            double idist = sqrt( pow(coord(j, 0) - coord(i, 0), 2) + pow(coord(j, 1) - coord(i, 1), 2) );

            if (i != j)
            {
                if (idist < delta+dx*1e-8)
                {
                    numfam(i) = numfam(i) + 1;
                    nodefam(pointfam(i) + numfam(i) - 1) = j;
                }

            }
        }
    }
    std::cout << "邻域粒子信息计算完毕！" << std::endl;

    //计算表面校正系数
    Eigen::MatrixXd predisp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd fncst = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd stendens = Eigen::MatrixXd::Zero(totnode, 2);

    // x 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.001 * coord(i, 0);
        predisp(i, 1) = 0.0;
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 0) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j );
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij +(predisp.row(famj)- predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 0) = stendens(i, 0) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij,2)  * xij * vol * fac;
        }
        fncst(i, 0) = sedload / stendens(i, 0);
    }

    // y 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.0;
        predisp(i, 1) = 0.001 * coord(i, 1);
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 1) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j);
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij + (predisp.row(famj) - predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 1) = stendens(i, 1) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij, 2) * xij * vol * fac;
        }
        fncst(i, 1) = sedload / stendens(i, 1);
    }

    //初始化键是否断裂的矩阵，0表示键断裂，1表示键完整
    Eigen::SparseMatrix<int> breakbond(totnode, totnode);
    for (int i = 0; i < totnode; i = i + 1)
    {
        for (int j = 0; j < numfam(i); j = j + 1)
        {
            int famj = nodefam(pointfam(i) + j );

            if ((( coord(famj, 0) < -length/2.0+cracklength ) || ( coord(i, 0) < -length/2.0+cracklength )) && coord(famj, 1) * coord(i, 1) < 0)
            {
                breakbond.coeffRef(i, famj) = 0;
            }
            else
            {
                breakbond.coeffRef(i, famj) = 1;
            }
        }
    }

    //提前声明的变量
    //初始化物质点的位移和速度矩阵
    Eigen::MatrixXd disp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd vel = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点所受的体力和键力矩阵
    Eigen::MatrixXd bodyforce = Eigen::MatrixXd::Zero(1, 2);
    bodyforce(0, 0) = 0;
    bodyforce(0, 1) = 0;
    Eigen::MatrixXd bondforce = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点损伤度的矩阵
    Eigen::VectorXd damage = Eigen::VectorXd::Zero(totnode);

    std::cout << "参数设置完毕！" << std::endl;

        //开始施加荷载步
        std::cout << "计算开始！" << std::endl;
        for (int tt = 1; tt <= nt; tt = tt + 1)
    {
        std::cout << "第 " << tt << " 步" << std::endl;

            // 施加边界：
            for (int i = (totint + 1); i <= totbottom1; i++)
        {
            vel(i, 1) = vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = (totbottom1 + 1); i <= totup; i++)
        {
            vel(i, 1) = -vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = 0; i < totnode; i++)
        {
            Eigen::MatrixXd forcei = Eigen::MatrixXd::Zero(1, 2);
            double breakindex = 0;

            for (int j = 0; j < numfam(i); j++)
            {
                int famj = nodefam( pointfam(i) + j );
                //计算键力
                Eigen::MatrixXd posij = ( coord.row(famj) - coord.row(i) );
                Eigen::MatrixXd curposij = posij+( disp.row(famj) - disp.row(i) );
                double xij = sqrt( pow(posij(0,0), 2) + pow(posij(0,1), 2) );
                double eta_xij = sqrt( pow(curposij(0,0), 2) + pow(curposij(0,1), 2) );
                double fac;
                if ( xij < (delta - radij) )
                {
                    fac = 1.0;
                }
                else if ( xij < (delta + radij) )
                {
                    fac = (delta + radij - xij) / (2 * radij);
                }
                else
                {
                    fac = 0.0;
                }
                double theta;
                if ( abs(coord(famj, 1) - coord(i, 1) ) <= 1e-12)
                {
                    theta = 0.0;
                }
                else if ( abs(coord(famj, 0) - coord(i, 0) ) <= 1e-12)
                {
                    theta = pi / 2.0;
                }
                else
                {
                    theta = atan( ( coord(famj, 1) - coord(i, 1) ) / ( coord(famj, 0) - coord(i, 0)  ) );
                }
                double scx = ( fncst(i, 0) + fncst(famj, 0) ) / 2.0;
                double scy = ( fncst(i, 1) + fncst(famj, 1) ) / 2.0;
                double scr = 1 / (  pow(cos(theta) / scx, 2) + pow(sin(theta) / scy, 2) );
                scr = sqrt(scr);
                double tempindx = breakbond.coeffRef(i, famj);
                forcei = forcei + tempindx * ( bc * (eta_xij / xij - 1) )* (vol * scr * fac)   * (curposij / eta_xij);
                //计算物质点的损伤值
                double s = (eta_xij - xij) / xij;
                if (s > s0)
                {
                    breakbond.coeffRef(i, famj) = 0;
                    breakindex = breakindex + 1;
                }
            }
            bondforce(i, 0) = forcei(0, 0) + bodyforce(0, 0);
            bondforce(i, 1) = forcei(0, 1) + bodyforce(0, 1);
            damage(i) = breakindex / numfam(i);
        }

        for (int i = 0; i < totnode; i++)
        {
            //更新速度和位移
            if ( (i > totint && i <= totbottom1) || (i > totbottom1 && i <= totup) )
            {
                vel(i, 0) = vel(i,0) + (dt/rho) * bondforce(i,0);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
            }
            else
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                vel(i, 1) = vel(i, 1) + (dt / rho) * bondforce(i, 1);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
                disp(i, 1) = disp(i, 1) + dt * vel(i, 1);
            }
        }

        //后处理输出到paraview
        std::string filename = "D:\\result\\GMPPD_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename);
        outfile << "# vtk DataFile Version 3.0" << std::endl;
        outfile << "L_shape_plate_crack" << std::endl;
        outfile << "ASCII" << std::endl;
        outfile << "DATASET UNSTRUCTURED_GRID" << std::endl;
        outfile << std::endl;
        outfile << "POINTS  " << (totup + 1) << "  double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i, 0)+coord(i,0) << std::setw(20) << disp(i, 1) + coord(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile << std::endl;
        outfile << "CELLS  " << (totup + 1) << "  " << 2 * (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << 1 << std::setw(20) << i << std::endl;
        }
        outfile << std::endl;
        outfile << "CELL_TYPES  " << (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << 1 << std::endl;
        }
        outfile << std::endl;
        outfile << "POINT_DATA  " << (totup + 1) << std::endl;
        outfile << "SCALARS dmg double 1" << std::endl;
        outfile << "LOOKUP_TABLE default" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << damage(i) << std::endl;
        }
        outfile << "VECTORS disp double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i,0) << std::setw(20) << disp(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile.close();
        //后处理结束
    }
}

void QWCalSoftware::calCtDmg()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paraL[8];
    //y方向点个数
    const int ndivy = paraL[9];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    //总荷载步数
    const int nt = paraL[7];
//    const int nt = 100;
    // 速度边界
    double vbd = paraL[10];
//    double vbd = 30;
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paraL[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paraL[4];
//    double width = 0.5;
    w = width;
    //初始裂纹长度
    double cracklength = paraL[6];
//    double cracklength = 0.5 * length;
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
    double thick = paraL[5];
//    double thick = min(dx,dy);
    //邻域半径
    double delta = 3.015 * sqrt(pow(dx, 2)+ pow(dy, 2));
    //邻域半径的一半，用于计算校正系数
    double radij = 0.5 * delta;
    //物质点面积
    double area = dx * dx;
    //物质点体积
    double vol = area * thick;
    // 材料密度
    //    double rho = 8000.0;
    double rho = paraL[2];
    //弹性模量
    //    double emod = 192.0e9;
    double emod = paraL[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
    //    double pratio = 0.3;
    double pratio = paraL[1];
    // 体积模量
    double kmod = emod / (2.0 * (1 - pratio));
    // 虚拟键参数
    double bc = 6 * emod / ((1.0 - pratio) * pi * thick * pow(delta, 3));
    // 临界拉伸率
    double s0 = 0.01; // sqrt(5.0 * G0 / (9.0 * kmod * delta));
    //时间步长
    double dt = 0.8 * sqrt(2.0 * rho * dx / ( pi * pow(delta, 2) * dx * bc) );
    // 提前施加的荷载，用于计算表面校正系数
    double sedload = (9.0/16.0) * emod * 1e-6;

    //物质点坐标生成
    //声明整体散点坐标矩阵
    Eigen::MatrixXd coord = Eigen::MatrixXd::Zero(totnode, 2);
    //确定内部点坐标
    int nnum = 0;
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= ndivy; j = j + 1)
        {
            double coordx = (-1.0 * length / 2.0) + (dx / 2.0) + (i - 1) * dx;
            double coordy = (-1.0 * width / 2.0) + (dx / 2.0) + (j - 1) * dx;
            coord(nnum, 0) = coordx;
            coord(nnum, 1) = coordy;
            nnum = nnum + 1;
        }
    }
    //内部点的编号结束点
    int totint = nnum - 1;
    //确定顶部边界点坐标

    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx ;
            coord(nnum, 1) = 1.0 / 2.0 * width + dx / 2.0 + (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //顶部边界点编号的结束点
    int totbottom1 = nnum - 1;
    //确定底部边界点坐标
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            coord(nnum, 0) = -1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx ;
            coord(nnum, 1) = -1.0 / 2.0 * width - dx / 2.0 - (j - 1) * dx;
            nnum = nnum + 1;
        }
    }
    //加载端边界点编号的结束点
    int totup = nnum - 1;
    std::cout << "物质点生成完毕！" << std::endl;

    //确定每一个物质点邻域内的邻域粒子
    Eigen::VectorXi numfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi pointfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi nodefam = Eigen::VectorXi::Zero(maxfam * totnode);

    for (int i = 0; i < totnode; i = i + 1)
    {
        if (i == 0)
        {
            pointfam(i) = 0;
        }
        else
        {
            pointfam(i) = pointfam(i - 1) + numfam(i - 1);
        }
        for (int j = 0; j < totnode; j = j + 1)
        {
            double idist = sqrt( pow(coord(j, 0) - coord(i, 0), 2) + pow(coord(j, 1) - coord(i, 1), 2) );

            if (i != j)
            {
                if (idist < delta+dx*1e-8)
                {
                    numfam(i) = numfam(i) + 1;
                    nodefam(pointfam(i) + numfam(i) - 1) = j;
                }

            }
        }
    }
    std::cout << "邻域粒子信息计算完毕！" << std::endl;

    //计算表面校正系数
    Eigen::MatrixXd predisp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd fncst = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd stendens = Eigen::MatrixXd::Zero(totnode, 2);

    // x 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.001 * coord(i, 0);
        predisp(i, 1) = 0.0;
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 0) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j );
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij +(predisp.row(famj)- predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 0) = stendens(i, 0) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij,2)  * xij * vol * fac;
        }
        fncst(i, 0) = sedload / stendens(i, 0);
    }

    // y 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.0;
        predisp(i, 1) = 0.001 * coord(i, 1);
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 1) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j);
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij + (predisp.row(famj) - predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 1) = stendens(i, 1) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij, 2) * xij * vol * fac;
        }
        fncst(i, 1) = sedload / stendens(i, 1);
    }

    //初始化键是否断裂的矩阵，0表示键断裂，1表示键完整
    Eigen::SparseMatrix<int> breakbond(totnode, totnode);
    for (int i = 0; i < totnode; i = i + 1)
    {
        for (int j = 0; j < numfam(i); j = j + 1)
        {
            int famj = nodefam(pointfam(i) + j );

            if (((abs(coord(famj, 0)) < 0.5 * cracklength) || (abs(coord(i, 0)) < 0.5 * cracklength)) && coord(famj, 1) * coord(i, 1) < 0)
            {
                breakbond.coeffRef(i, famj) = 0;
            }
            else
            {
                breakbond.coeffRef(i, famj) = 1;
            }
        }
    }

    //提前声明的变量
    //初始化物质点的位移和速度矩阵
    Eigen::MatrixXd disp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd vel = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点所受的体力和键力矩阵
    Eigen::MatrixXd bodyforce = Eigen::MatrixXd::Zero(1, 2);
    bodyforce(0, 0) = 0;
    bodyforce(0, 1) = 0;
    Eigen::MatrixXd bondforce = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点损伤度的矩阵
    Eigen::VectorXd damage = Eigen::VectorXd::Zero(totnode);

    std::cout << "参数设置完毕！" << std::endl;

        //开始施加荷载步
        std::cout << "计算开始！" << std::endl;
        for (int tt = 1; tt <= nt; tt = tt + 1)
    {
        std::cout << "第 " << tt << " 步" << std::endl;

            // 施加边界：
            for (int i = (totint + 1); i <= totbottom1; i++)
        {
            vel(i, 1) = vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = (totbottom1 + 1); i <= totup; i++)
        {
            vel(i, 1) = -vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = 0; i < totnode; i++)
        {
            Eigen::MatrixXd forcei = Eigen::MatrixXd::Zero(1, 2);
            double breakindex = 0;

            for (int j = 0; j < numfam(i); j++)
            {
                int famj = nodefam( pointfam(i) + j );
                //计算键力
                Eigen::MatrixXd posij = ( coord.row(famj) - coord.row(i) );
                Eigen::MatrixXd curposij = posij+( disp.row(famj) - disp.row(i) );
                double xij = sqrt( pow(posij(0,0), 2) + pow(posij(0,1), 2) );
                double eta_xij = sqrt( pow(curposij(0,0), 2) + pow(curposij(0,1), 2) );
                double fac;
                if ( xij < (delta - radij) )
                {
                    fac = 1.0;
                }
                else if ( xij < (delta + radij) )
                {
                    fac = (delta + radij - xij) / (2 * radij);
                }
                else
                {
                    fac = 0.0;
                }
                double theta;
                if ( abs(coord(famj, 1) - coord(i, 1) ) <= 1e-12)
                {
                    theta = 0.0;
                }
                else if ( abs(coord(famj, 0) - coord(i, 0) ) <= 1e-12)
                {
                    theta = pi / 2.0;
                }
                else
                {
                    theta = atan( ( coord(famj, 1) - coord(i, 1) ) / ( coord(famj, 0) - coord(i, 0)  ) );
                }
                double scx = ( fncst(i, 0) + fncst(famj, 0) ) / 2.0;
                double scy = ( fncst(i, 1) + fncst(famj, 1) ) / 2.0;
                double scr = 1 / (  pow(cos(theta) / scx, 2) + pow(sin(theta) / scy, 2) );
                scr = sqrt(scr);
                double tempindx = breakbond.coeffRef(i, famj);
                forcei = forcei + tempindx * ( bc * (eta_xij / xij - 1) )* (vol * scr * fac)   * (curposij / eta_xij);
                //计算物质点的损伤值
                double s = (eta_xij - xij) / xij;
                if (s > s0)
                {
                    breakbond.coeffRef(i, famj) = 0;
                    breakindex = breakindex + 1;
                }
            }
            bondforce(i, 0) = forcei(0, 0) + bodyforce(0, 0);
            bondforce(i, 1) = forcei(0, 1) + bodyforce(0, 1);
            damage(i) = breakindex / numfam(i);
        }

        for (int i = 0; i < totnode; i++)
        {
            //更新速度和位移
            if ( (i > totint && i <= totbottom1) || (i > totbottom1 && i <= totup) )
            {
                vel(i, 0) = vel(i,0) + (dt/rho) * bondforce(i,0);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
            }
            else
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                vel(i, 1) = vel(i, 1) + (dt / rho) * bondforce(i, 1);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
                disp(i, 1) = disp(i, 1) + dt * vel(i, 1);
            }
        }

        //后处理输出到paraview
        std::string filename = "D:\\result\\GMPPD_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename);
        outfile << "# vtk DataFile Version 3.0" << std::endl;
        outfile << "L_shape_plate_crack" << std::endl;
        outfile << "ASCII" << std::endl;
        outfile << "DATASET UNSTRUCTURED_GRID" << std::endl;
        outfile << std::endl;
        outfile << "POINTS  " << (totup + 1) << "  double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i, 0)+coord(i,0) << std::setw(20) << disp(i, 1) + coord(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile << std::endl;
        outfile << "CELLS  " << (totup + 1) << "  " << 2 * (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << 1 << std::setw(20) << i << std::endl;
        }
        outfile << std::endl;
        outfile << "CELL_TYPES  " << (totup + 1) << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << 1 << std::endl;
        }
        outfile << std::endl;
        outfile << "POINT_DATA  " << (totup + 1) << std::endl;
        outfile << "SCALARS dmg double 1" << std::endl;
        outfile << "LOOKUP_TABLE default" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << damage(i) << std::endl;
        }
        outfile << "VECTORS disp double" << std::endl;
        for (int i = 0; i <= totup; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i,0) << std::setw(20) << disp(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile.close();
        //后处理结束
    }
}

void QWCalSoftware::calLBoard()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paraL[7];
    //y方向点个数
    const int ndivy = paraL[8];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层，L板总的点个数需要在建立物质点模型时计算
    int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    // 速度边界
    double vbd = paraL[9];
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paraL[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paraL[4];
//    double width = 0.5;
    w = length;
    //L板右下空缺处
    double Llength = 0.5/2;
    //L板右下空缺处
    double Lwidth = 0.5/2;
    //无初始裂纹
    //double cracklength = 0.5 * length;
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
    double thick = paraL[5];
//    double thick = dx;
    //邻域半径
    double delta = 3.015 * sqrt(pow(dx, 2)+ pow(dy, 2));
    //邻域半径的一半，用于计算校正系数
    double radij = 0.5 * delta;
    //物质点面积
    double area = dx * dx;
    //物质点体积
    double vol = area * thick;
    // 材料密度
    double rho = paraL[2];
//    double rho = 2265.0;
    //弹性模量
    double emod = paraL[0];
//    double emod = 25.85e9;
    //临界能量释放率
    double G0 = 65.0;
    //泊松比 0.18，键型可以么？
    double pratio = paraL[1];
//    double pratio = 0.3;
    // 体积模量
    double kmod = emod / (2.0 * (1 - pratio));
    // 虚拟键参数
    double bc = 6 * emod / ((1.0 - pratio) * pi * thick * pow(delta, 3));
    // 临界拉伸率
    double s0 = 0.01; // sqrt(5.0 * G0 / (9.0 * kmod * delta));
    //时间步长
    double dt = 0.8 * sqrt(2.0 * rho * dx / ( pi * pow(delta, 2) * dx * bc) );
    //总加载时间
    double totalTime = 0.002;
    //总荷载步数
    const int nt = paraL[6];
//    const int nt = 100;
//    const int nt = floor(totalTime / dt);
    // 提前施加的荷载，用于计算表面校正系数
    double sedload = (9.0/16.0) * emod * 1e-6;

    //物质点坐标生成
    //声明整体散点坐标矩阵
    Eigen::MatrixXd coord = Eigen::MatrixXd::Zero(totnode, 2);
    //确定内部点坐标
    int nnum = 0;
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= ndivy; j = j + 1)
        {
            double coordx = (-1.0 * length / 2.0) + (dx / 2.0) + (i - 1) * dx;
            double coordy = (-1.0 * width / 2.0) + (dx / 2.0) + (j - 1) * dx;
            //判断L板的范围，去除右下角边长为Llength*Lwidth的区域
            if ( (coordx > -length/2+(length-Llength)) && (coordy < -width/2+(width-Lwidth)))
            {

            }
            else
            {
                coord(nnum, 0) = coordx;
                coord(nnum, 1) = coordy;
                nnum = nnum + 1;
            }


        }
    }
    //内部点的编号结束点
    int totint = nnum - 1;
    //确定底部边界点坐标
    for (int i = 1; i <= ndivx; i = i + 1)
    {
        for (int j = 1; j <= nbnd; j = j + 1)
        {
            double coordx = (-1.0 * length / 2.0) + (dx / 2.0) + (i - 1) * dx;
            double coordy = (-1.0 * width / 2.0) - (dx / 2.0) - (j - 1) * dx;
            if (coordx <= -length/2+(length-Llength))
            {
                coord(nnum, 0) = coordx ;
                coord(nnum, 1) = coordy;
                nnum = nnum + 1;
            }
        }
    }
    //底部边界点编号的结束点
    int totbottom1 = nnum - 1;
    //确定右边边界点坐标
    for (int i = 1; i <= nbnd; i = i + 1)
    {
        for (int j = 1; j <= ndivy; j = j + 1)
        {
            double coordx = 1.0 / 2.0 * length + dx / 2.0 + (i - 1) * dx ;
            double coordy = -1.0 / 2.0 * width + dx / 2.0 + (j - 1) * dx;
            if (coordy >= -width/2+(width-Lwidth))
            {
                coord(nnum, 0) = coordx ;
                coord(nnum, 1) = coordy ;
                nnum = nnum + 1;
            }

        }
    }
    //加载端边界点编号的结束点
    int totright = nnum - 1;
    totnode = nnum;

    std::cout << "物质点生成完毕！" << std::endl;

    //确定每一个物质点邻域内的邻域粒子
    Eigen::VectorXi numfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi pointfam = Eigen::VectorXi::Zero(totnode);
    Eigen::VectorXi nodefam = Eigen::VectorXi::Zero(maxfam * totnode);

    for (int i = 0; i < totnode; i = i + 1)
    {
        if (i == 0)
        {
            pointfam(i) = 0;
        }
        else
        {
            pointfam(i) = pointfam(i - 1) + numfam(i - 1);
        }
        for (int j = 0; j < totnode; j = j + 1)
        {
            double idist = sqrt( pow(coord(j, 0) - coord(i, 0), 2) + pow(coord(j, 1) - coord(i, 1), 2) );

            if (i != j)
            {
                if (idist < delta+dx*1e-8)
                {
                    numfam(i) = numfam(i) + 1;
                    nodefam(pointfam(i) + numfam(i) - 1) = j;
                }

            }
        }
    }

    std::cout << "邻域粒子信息计算完毕！" << std::endl;
    //计算表面校正系数
    Eigen::MatrixXd predisp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd fncst = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd stendens = Eigen::MatrixXd::Zero(totnode, 2);

    // x 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.001 * coord(i, 0);
        predisp(i, 1) = 0.0;
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 0) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j );
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij +(predisp.row(famj)- predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 0) = stendens(i, 0) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij,2)  * xij * vol * fac;
        }
        fncst(i, 0) = sedload / stendens(i, 0);

    }

    // y 方向加载
    for (int i = 0; i < totnode; i = i + 1)
    {
        predisp(i, 0) = 0.0;
        predisp(i, 1) = 0.001 * coord(i, 1);
    }

    for (int i = 0; i < totnode; i = i + 1)
    {
        stendens(i, 1) = 0;
        for (int j = 0; j < numfam(i); j++)
        {
            int famj = nodefam(pointfam(i) + j);
            Eigen::MatrixXd posij = coord.row(famj) - coord.row(i);
            Eigen::MatrixXd curposij = posij + (predisp.row(famj) - predisp.row(i));
            double xij = sqrt(pow(posij(0, 0), 2) + pow(posij(0, 1), 2));
            double eta_xij = sqrt(pow(curposij(0, 0), 2) + pow(curposij(0, 1), 2));
            double fac;
            if (xij < (delta - radij))
            {
                fac = 1.0;
            }
            else if (xij < (delta + radij))
            {
                fac = (delta + radij - xij) / (2 * radij);
            }
            else
            {
                fac = 0.0;
            }
            stendens(i, 1) = stendens(i, 1) + 0.5 * 0.5 * bc * pow((eta_xij - xij) / xij, 2) * xij * vol * fac;
        }
        fncst(i, 1) = sedload / stendens(i, 1);
    }

    //初始化键是否断裂的矩阵，0表示键断裂，1表示键完整
    Eigen::SparseMatrix<int> breakbond(totnode, totnode);
    for (int i = 0; i < totnode; i = i + 1)
    {
        for (int j = 0; j < numfam(i); j = j + 1)
        {
            int famj = nodefam(pointfam(i) + j );


            breakbond.coeffRef(i, famj) = 1;

        }
    }

    //提前声明的变量
    //初始化物质点的位移和速度矩阵
    Eigen::MatrixXd disp = Eigen::MatrixXd::Zero(totnode, 2);
    Eigen::MatrixXd vel = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点所受的体力和键力矩阵
    Eigen::MatrixXd bodyforce = Eigen::MatrixXd::Zero(1, 2);
    bodyforce(0, 0) = 0;
    bodyforce(0, 1) = 0;
    Eigen::MatrixXd bondforce = Eigen::MatrixXd::Zero(totnode, 2);
    //初始化物质点损伤度的矩阵
    Eigen::VectorXd damage = Eigen::VectorXd::Zero(totnode);

    std::cout << "参数设置完毕！" << std::endl;

        //开始施加荷载步
        std::cout << "计算开始！" << std::endl;
        for (int tt = 1; tt <= nt; tt = tt + 1)
    {
        std::cout << "第 " << tt << " 步" << std::endl;

            // 施加边界：
            // 底边x，y方向固定
            for (int i = (totint + 1); i <= totbottom1; i++)
        {
            vel(i, 1) = 0;
            disp(i, 1) = vel(i, 1) * tt * dt;
            vel(i, 0) = 0;
            disp(i, 0) = vel(i, 1) * tt * dt;
        }
        // 右边界给y方向向上的位移
        for (int i = (totbottom1 + 1); i <= totright; i++)
        {
            vel(i, 1) = vbd;
            disp(i, 1) = vel(i, 1) * tt * dt;
        }

        for (int i = 0; i < totnode; i++)
        {
            Eigen::MatrixXd forcei = Eigen::MatrixXd::Zero(1, 2);
            double breakindex = 0;

            for (int j = 0; j < numfam(i); j++)
            {
                int famj = nodefam( pointfam(i) + j );
                //计算键力
                Eigen::MatrixXd posij = ( coord.row(famj) - coord.row(i) );
                Eigen::MatrixXd curposij = posij+( disp.row(famj) - disp.row(i) );
                double xij = sqrt( pow(posij(0,0), 2) + pow(posij(0,1), 2) );
                double eta_xij = sqrt( pow(curposij(0,0), 2) + pow(curposij(0,1), 2) );
                double fac;
                if ( xij < (delta - radij) )
                {
                    fac = 1.0;
                }
                else if ( xij < (delta + radij) )
                {
                    fac = (delta + radij - xij) / (2 * radij);
                }
                else
                {
                    fac = 0.0;
                }
                double theta;
                if ( abs(coord(famj, 1) - coord(i, 1) ) <= 1e-12)
                {
                    theta = 0.0;
                }
                else if ( abs(coord(famj, 0) - coord(i, 0) ) <= 1e-12)
                {
                    theta = pi / 2.0;
                }
                else
                {
                    theta = atan( ( coord(famj, 1) - coord(i, 1) ) / ( coord(famj, 0) - coord(i, 0)  ) );
                }
                double scx = ( fncst(i, 0) + fncst(famj, 0) ) / 2.0;
                double scy = ( fncst(i, 1) + fncst(famj, 1) ) / 2.0;
                double scr = 1 / (  pow(cos(theta) / scx, 2) + pow(sin(theta) / scy, 2) );
                scr = sqrt(scr);
                double tempindx = breakbond.coeffRef(i, famj);
                forcei = forcei + tempindx * ( bc * (eta_xij / xij - 1) )* (vol * scr * fac)   * (curposij / eta_xij);
                //计算物质点的损伤值
                double s = (eta_xij - xij) / xij;
                //避免右边边界处发生损伤，限制损伤出现的区域
                if (coord(i,0)< length/4)
                {
                    if (s > s0)
                    {
                        breakbond.coeffRef(i, famj) = 0;
                        breakindex = breakindex + 1;
                    }
                }


            }
            bondforce(i, 0) = forcei(0, 0) + bodyforce(0, 0);
            bondforce(i, 1) = forcei(0, 1) + bodyforce(0, 1);
            damage(i) = breakindex / numfam(i);
        }


        for (int i = 0; i < totnode; i++)
        {
            //更新速度和位移，重复输入了一下底边固定边界条件
            if ( (i > totint && i <= totbottom1) )
            {
                vel(i, 0) = 0;
                disp(i, 0) = 0;
                vel(i, 1) = 0;
                disp(i, 1) = 0;
            }
            else if (i > totbottom1 && i <= totright)
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
            }
            else
            {
                vel(i, 0) = vel(i, 0) + (dt / rho) * bondforce(i, 0);
                vel(i, 1) = vel(i, 1) + (dt / rho) * bondforce(i, 1);
                disp(i, 0) = disp(i, 0) + dt * vel(i, 0);
                disp(i, 1) = disp(i, 1) + dt * vel(i, 1);
            }
        }

        //后处理输出到paraview
        std::string filename = "D:\\result\\GMPPD_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename);
        outfile << "# vtk DataFile Version 3.0" << std::endl;
        outfile << "L_shape_plate_crack" << std::endl;
        outfile << "ASCII" << std::endl;
        outfile << "DATASET UNSTRUCTURED_GRID" << std::endl;
        outfile << std::endl;
        outfile << "POINTS  " << (totright + 1) << "  double" << std::endl;
        for (int i = 0; i <= totright; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i, 0)+coord(i,0) << std::setw(20) << disp(i, 1) + coord(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile << std::endl;
        outfile << "CELLS  " << (totright + 1) << "  " << 2 * (totright + 1) << std::endl;
        for (int i = 0; i <= totright; i = i + 1)
        {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << 1 << std::setw(20) << i << std::endl;
        }
        outfile << std::endl;
        outfile << "CELL_TYPES  " << (totright + 1) << std::endl;
        for (int i = 0; i <= totright; i = i + 1)
        {
            outfile << 1 << std::endl;
        }
        outfile << std::endl;
        outfile << "POINT_DATA  " << (totright + 1) << std::endl;
        outfile << "SCALARS dmg double 1" << std::endl;
        outfile << "LOOKUP_TABLE default" << std::endl;
        for (int i = 0; i <= totright; i = i + 1)
        {
            outfile << damage(i) << std::endl;
        }
        outfile << "VECTORS disp double" << std::endl;
        for (int i = 0; i <= totright; i = i + 1)
            {
            outfile << std::setiosflags(std::ios::left) << std::setw(20) << disp(i,0) << std::setw(20) << disp(i, 1) << std::setw(20) << 0.0 << std::endl;
        }
        outfile.close();
        //后处理结束
    }
}

void QWCalSoftware::paintScatter(int n,QImage &image1,QImage &image2,QImage &image3)
{
    QString str1="D:\\result\\GMPPD_";
    QString str2=QString::number(n);
    QString str3=".vtk";
    QString filename = str1+str2+str3;
    QFile file(filename);
    if(!file.exists())return;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))return; //打开文件

    QString str;
    QStringList strList;
    QVector<qreal> x,y,dmg,xdisp,ydisp;
    QTextStream stream(&file);
    while(!stream.readLine().contains("POINTS")){}
    str = stream.readLine();
    while(str.length())
    {
        str.replace(QRegExp("[\\s]+"), " ");
        strList = str.split(" ");
        x<<strList[0].toFloat();
        y<<strList[1].toFloat();
        str = stream.readLine();
    } //寻找x,y值

    while(!stream.readLine().contains("LOOKUP_TABLE")){}
    str = stream.readLine();
    while(!str.contains("VECTORS disp"))
    {
        dmg<<str.toFloat();
        str = stream.readLine();
    } //寻找dmg值

    str = stream.readLine();
    while(!stream.atEnd())
    {
        str.replace(QRegExp("[\\s]+"), " ");
        strList = str.split(" ");
        xdisp<<strList[0].toFloat();
        ydisp<<strList[1].toFloat();
        str = stream.readLine();
    } //寻找disp值

    str.replace(QRegExp("[\\s]+"), " ");
    strList = str.split(" ");
    xdisp<<strList[0].toFloat();
    ydisp<<strList[1].toFloat(); //补全最后一条记录

    file.close(); //关闭文件

    QString filename0="C:\\Users\\dell\\Desktop\\test.png";
    QFile file0(filename0);
    if(!file.exists())
    {
        file0.remove();
    } //删除已有图片

    QColor backColor = qRgb(255, 255, 255);
    image1 = QImage(800, 600, QImage::Format_RGB32);
    image1.fill(backColor);
    image2 = QImage(800, 600, QImage::Format_RGB32);
    image2.fill(backColor);
    image3 = QImage(800, 600, QImage::Format_RGB32);
    image3.fill(backColor); //设置画布

    QColor color1=qRgb(0, 0,128 + 4 * (7 - 0));
    QColor color2=qRgb(0, 0,128 + 4 * (23 - 0));
    QColor color3=qRgb(0, 4 + 4 * (39 - 33),255);
    QColor color4=qRgb(0, 4 + 4 * (55 - 33),255);
    QColor color5=qRgb(0, 4 + 4 * (71 - 33),255);
    QColor color6=qRgb(0, 4 + 4 * (87 - 33),255);
    QColor color7=qRgb(6 + 4 * (103 - 97), 255,250 - 4 * (103 - 97));
    QColor color8=qRgb(6 + 4 * (119 - 97), 255,250 - 4 * (119 - 97));
    QColor color9=qRgb(6 + 4 * (135 - 97), 255,250 - 4 * (135 - 97));
    QColor color10=qRgb(6 + 4 * (151 - 97), 255,250 - 4 * (151 - 97));
    QColor color11=qRgb(255, 252 - 4 * (167 - 160),0);
    QColor color12=qRgb(255, 252 - 4 * (183 - 160),0);
    QColor color13=qRgb(255, 252 - 4 * (199 - 160),0);
    QColor color14=qRgb(255, 252 - 4 * (215 - 160),0);
    QColor color15=qRgb(252 - 4 * (231 - 224),0,0);
    QColor color16=qRgb(252 - 4 * (247 - 224),0,0); //设置不同颜色

//    QBrush brush;
//    brush.setColor(Qt::red);
//    brush.setStyle(Qt::Dense1Pattern);
    QBrush brush1;
    brush1.setColor(color1);
    brush1.setStyle(Qt::Dense1Pattern);
    QBrush brush2;
    brush2.setColor(color2);
    brush2.setStyle(Qt::Dense1Pattern);
    QBrush brush3;
    brush3.setColor(color3);
    brush3.setStyle(Qt::Dense1Pattern);
    QBrush brush4;
    brush4.setColor(color4);
    brush4.setStyle(Qt::Dense1Pattern);
    QBrush brush5;
    brush5.setColor(color5);
    brush5.setStyle(Qt::Dense1Pattern);
    QBrush brush6;
    brush6.setColor(color6);
    brush6.setStyle(Qt::Dense1Pattern);
    QBrush brush7;
    brush7.setColor(color7);
    brush7.setStyle(Qt::Dense1Pattern);
    QBrush brush8;
    brush8.setColor(color8);
    brush8.setStyle(Qt::Dense1Pattern);
    QBrush brush9;
    brush9.setColor(color9);
    brush9.setStyle(Qt::Dense1Pattern);
    QBrush brush10;
    brush10.setColor(color10);
    brush10.setStyle(Qt::Dense1Pattern);
    QBrush brush11;
    brush11.setColor(color11);
    brush11.setStyle(Qt::Dense1Pattern);
    QBrush brush12;
    brush12.setColor(color12);
    brush12.setStyle(Qt::Dense1Pattern);
    QBrush brush13;
    brush13.setColor(color13);
    brush13.setStyle(Qt::Dense1Pattern);
    QBrush brush14;
    brush14.setColor(color14);
    brush14.setStyle(Qt::Dense1Pattern);
    QBrush brush15;
    brush15.setColor(color15);
    brush15.setStyle(Qt::Dense1Pattern);
    QBrush brush16;
    brush16.setColor(color16);
    brush16.setStyle(Qt::Dense1Pattern); //设置笔刷

    QPainter painter1 = QPainter(&image1);
    painter1.setRenderHint(QPainter::Antialiasing, true);
    QPainter painter2 = QPainter(&image2);
    painter2.setRenderHint(QPainter::Antialiasing, true);
    QPainter painter3 = QPainter(&image3);
    painter3.setRenderHint(QPainter::Antialiasing, true);

    QPen pen1;
    pen1.setColor(color1);
    QPen pen2;
    pen2.setColor(color2);
    QPen pen3;
    pen3.setColor(color3);
    QPen pen4;
    pen4.setColor(color4);
    QPen pen5;
    pen5.setColor(color5);
    QPen pen6;
    pen6.setColor(color6);
    QPen pen7;
    pen7.setColor(color7);
    QPen pen8;
    pen8.setColor(color8);
    QPen pen9;
    pen9.setColor(color9);
    QPen pen10;
    pen10.setColor(color10);
    QPen pen11;
    pen11.setColor(color11);
    QPen pen12;
    pen12.setColor(color12);
    QPen pen13;
    pen13.setColor(color13);
    QPen pen14;
    pen14.setColor(color14);
    QPen pen15;
    pen15.setColor(color15);
    QPen pen16;
    pen16.setColor(color16);


//    painter1.setBrush(brush);
//    brush.setStyle(Qt::Dense1Pattern);

    qreal dmgMax = *max_element(dmg.begin(), dmg.end());
    qreal dmgMin = *min_element(dmg.begin(), dmg.end());
    if (dmgMax==0)dmgMax=1;
    int gray; //设置颜色映射变量

    for(int i = 0;i<x.size();i++)
    {
        gray = (dmg[i]-dmgMin)/(dmgMax-dmgMin)*255;
        if(gray >= 0 && gray <= 15)
        {
            painter1.setBrush(brush1);
            painter1.setPen(pen1);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 16 && gray <= 31)
        {
            painter1.setBrush(brush2);
            painter1.setPen(pen2);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 32 && gray <= 47)
        {
            painter1.setBrush(brush3);
            painter1.setPen(pen3);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 48 && gray <= 63)
        {
            painter1.setBrush(brush4);
            painter1.setPen(pen4);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 64 && gray <= 79)
        {
            painter1.setBrush(brush5);
            painter1.setPen(pen5);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 80 && gray <= 95)
        {
            painter1.setBrush(brush6);
            painter1.setPen(pen6);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 96 && gray <= 111)
        {
            painter1.setBrush(brush7);
            painter1.setPen(pen7);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 112 && gray <= 127)
        {
            painter1.setBrush(brush8);
            painter1.setPen(pen8);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 128 && gray <= 143)
        {
            painter1.setBrush(brush9);
            painter1.setPen(pen9);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 144 && gray <= 159)
        {
            painter1.setBrush(brush10);
            painter1.setPen(pen10);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 160 && gray <= 175)
        {
            painter1.setBrush(brush11);
            painter1.setPen(pen11);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 176 && gray <= 191)
        {
            painter1.setBrush(brush12);
            painter1.setPen(pen12);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 192 && gray <= 207)
        {
            painter1.setBrush(brush13);
            painter1.setPen(pen13);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 208 && gray <= 223)
        {
            painter1.setBrush(brush14);
            painter1.setPen(pen14);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 224 && gray <= 239)
        {
            painter1.setBrush(brush15);
            painter1.setPen(pen15);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
        else if(gray >= 240 && gray <= 255)
        {
            painter1.setBrush(brush16);
            painter1.setPen(pen16);
            painter1.drawEllipse(QPoint(x[i]*l*1600+330,y[i]*w*1600+300),10,10);
        }
    } //画散点图

    QRect section;
    QColor color;
    float colorBarLength=343.0;

    float tempLength=colorBarLength/4; //85.75
    for(int i=0;i<tempLength/2;i++) //0-42
    {
        color.setRgbF(0,0,(tempLength/2+i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter1.fillRect(section,color);
    }
    for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++) //43-128
    {
        color.setRgbF(0,(i-tempLength/2)/tempLength,1);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter1.fillRect(section,color);
    }
    for(int i=tempLength/2+tempLength+1;i<tempLength/2+2*tempLength;i++) //129-214
    {
        color.setRgbF((i-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter1.fillRect(section,color);
    }
    for(int i=tempLength/2+2*tempLength+1;i<tempLength/2+3*tempLength;i++) //215-300
    {
        color.setRgbF(1,(tempLength*3+tempLength/2-i)/tempLength,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter1.fillRect(section,color);
    }
    for(int i=tempLength/2+3*tempLength+1;i<colorBarLength;i++) //301-342
    {
        color.setRgbF((colorBarLength-i+tempLength/2)/(tempLength),0,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter1.fillRect(section,color);
    } //画色条

    QFont font;
    font.setBold(true);
    font.setFamily("Microsoft YaHei");
    font.setPointSize(12);
    painter1.setFont(font);
    painter2.setFont(font);
    painter3.setFont(font);//设置字体


    painter1.drawText(650,130,QString::number(dmgMax));
    painter1.drawText(670,135+353,QString::number(dmgMin)); //显示最大最小值

//    image.save("C:\\Users\\dell\\Desktop\\test2.png");
//    cout<<"#########################"<<endl;

    qreal xdispMax = *max_element(xdisp.begin(), xdisp.end());
    qreal xdispMin = *min_element(xdisp.begin(), xdisp.end());
    qreal ydispMax = *max_element(ydisp.begin(), ydisp.end());
    qreal ydispMin = *min_element(ydisp.begin(), ydisp.end()); //获得x y方向最大、最小值

    QVectorIterator<qreal> i(x);
    QVectorIterator<qreal> j(y);
    QVectorIterator<qreal> id(xdisp);
    QVectorIterator<qreal> jd(ydisp); //设置迭代器

    while(id.hasNext())
    {
        int grayD = colorBarLength * (xdispMax-id.next()) / (xdispMax-xdispMin);
        if(grayD<tempLength/2)
        {
            color.setRgbF(0,0,(tempLength/2+grayD)/tempLength);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter2.fillRect(section,color);
        }
        else if(grayD>tempLength/2 && grayD<tempLength/2+tempLength)
        {
            color.setRgbF(0,(grayD-tempLength/2)/tempLength,1);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter2.fillRect(section,color);
        }
        else if(grayD>tempLength/2+tempLength && grayD<tempLength/2+2*tempLength)
        {
            color.setRgbF((grayD-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-grayD)/tempLength);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter2.fillRect(section,color);
        }
        else if(grayD>tempLength/2+2*tempLength && grayD<tempLength/2+3*tempLength)
        {
            color.setRgbF(1,(tempLength*3+tempLength/2-grayD)/tempLength,0);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter2.fillRect(section,color);
        }
        else if(grayD>tempLength/2+3*tempLength && grayD<=colorBarLength)
        {
            color.setRgbF((colorBarLength-grayD+tempLength/2)/(tempLength),0,0);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter2.fillRect(section,color);
        }
    } //画x位移图

    for(int i=0;i<tempLength/2;i++) //0-42
    {
        color.setRgbF(0,0,(tempLength/2+i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter2.fillRect(section,color);
    }
    for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++) //43-128
    {
        color.setRgbF(0,(i-tempLength/2)/tempLength,1);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter2.fillRect(section,color);
    }
    for(int i=tempLength/2+tempLength+1;i<tempLength/2+2*tempLength;i++) //129-214
    {
        color.setRgbF((i-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter2.fillRect(section,color);
    }
    for(int i=tempLength/2+2*tempLength+1;i<tempLength/2+3*tempLength;i++) //215-300
    {
        color.setRgbF(1,(tempLength*3+tempLength/2-i)/tempLength,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter2.fillRect(section,color);
    }
    for(int i=tempLength/2+3*tempLength+1;i<colorBarLength;i++) //301-342
    {
        color.setRgbF((colorBarLength-i+tempLength/2)/(tempLength),0,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter2.fillRect(section,color);
    } //画第二个色条

    painter2.drawText(650,130,QString::number(xdispMax));
    painter2.drawText(650,135+353,QString::number(xdispMin)); //显示最大最小值

    i.toFront();
    j.toFront(); //恢复指针位置

    while(jd.hasNext())
    {
        int grayD = colorBarLength * (ydispMax-jd.next()) / (ydispMax-ydispMin);
        if(grayD<tempLength/2)
        {
            color.setRgbF(0,0,(tempLength/2+grayD)/tempLength);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter3.fillRect(section,color);
        }
        else if(grayD>tempLength/2 && grayD<tempLength/2+tempLength)
        {
            color.setRgbF(0,(grayD-tempLength/2)/tempLength,1);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter3.fillRect(section,color);
        }
        else if(grayD>tempLength/2+tempLength && grayD<tempLength/2+2*tempLength)
        {
            color.setRgbF((grayD-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-grayD)/tempLength);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter3.fillRect(section,color);
        }
        else if(grayD>tempLength/2+2*tempLength && grayD<tempLength/2+3*tempLength)
        {
            color.setRgbF(1,(tempLength*3+tempLength/2-grayD)/tempLength,0);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter3.fillRect(section,color);
        }
        else if(grayD>tempLength/2+3*tempLength && grayD<=colorBarLength)
        {
            color.setRgbF((colorBarLength-grayD+tempLength/2)/(tempLength),0,0);
            section.setRect(i.next()*l*1600+300,j.next()*w*1600+300,15,15);
            painter3.fillRect(section,color);
        }
    } //画y位移图

    for(int i=0;i<tempLength/2;i++) //0-42
    {
        color.setRgbF(0,0,(tempLength/2+i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter3.fillRect(section,color);
    }
    for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++) //43-128
    {
        color.setRgbF(0,(i-tempLength/2)/tempLength,1);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter3.fillRect(section,color);
    }
    for(int i=tempLength/2+tempLength+1;i<tempLength/2+2*tempLength;i++) //129-214
    {
        color.setRgbF((i-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-i)/tempLength);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter3.fillRect(section,color);
    }
    for(int i=tempLength/2+2*tempLength+1;i<tempLength/2+3*tempLength;i++) //215-300
    {
        color.setRgbF(1,(tempLength*3+tempLength/2-i)/tempLength,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter3.fillRect(section,color);
    }
    for(int i=tempLength/2+3*tempLength+1;i<colorBarLength;i++) //301-342
    {
        color.setRgbF((colorBarLength-i+tempLength/2)/(tempLength),0,0);
        section.setRect(200+500,colorBarLength+50-i*1+80,20,1);
        painter3.fillRect(section,color);
    } //画第三个色条

    painter3.drawText(650,130,QString::number(ydispMax));
    painter3.drawText(650,135+353,QString::number(ydispMin)); //显示最大最小值

}

void QWCalSoftware::on_pushButton_clicked()
{
    int tag = sortComboBox->currentIndex();
    if(tag==0){
        QWParaInput *dlg=new QWParaInput(this);
        Qt::WindowFlags flags=dlg->windowFlags();
        dlg->setWindowFlags(flags|Qt::MSWindowsFixedSizeDialogHint);
        int ret=dlg->exec();
        if(ret==QDialog::Accepted)
        {
            QList<float> list;
            list<<dlg->paraList[0]<<dlg->paraList[1]<<dlg->paraList[2]<<dlg->paraList[3]<<dlg->paraList[4]<<dlg->paraList[5]<<dlg->paraList[6]<<dlg->paraList[7]<<dlg->paraList[8]<<dlg->paraList[9]<<dlg->paraList[10];
            paraL = list;
            proIndex = 0;
//            cout<<paraL[0]<<"#############"<<endl;
        }
    }
    if(tag==1){
        QWParaInput2 *dlg=new QWParaInput2(this);
        Qt::WindowFlags flags=dlg->windowFlags();
        dlg->setWindowFlags(flags|Qt::MSWindowsFixedSizeDialogHint);
        int ret=dlg->exec();
        if(ret==QDialog::Accepted)
        {
            QList<float> list;
            list<<dlg->paraList[0]<<dlg->paraList[1]<<dlg->paraList[2]<<dlg->paraList[3]<<dlg->paraList[4]<<dlg->paraList[5]<<dlg->paraList[6]<<dlg->paraList[7]<<dlg->paraList[8]<<dlg->paraList[9]<<dlg->paraList[10];
            paraL = list;
            proIndex = 1;
        }
    }
    if(tag==2){
        QWParaInput3 *dlg=new QWParaInput3(this);
        Qt::WindowFlags flags=dlg->windowFlags();
        dlg->setWindowFlags(flags|Qt::MSWindowsFixedSizeDialogHint);
        int ret=dlg->exec();
        if(ret==QDialog::Accepted)
        {
            QList<float> list;
            list<<dlg->paraList[0]<<dlg->paraList[1]<<dlg->paraList[2]<<dlg->paraList[3]<<dlg->paraList[4]<<dlg->paraList[5]<<dlg->paraList[6]<<dlg->paraList[7]<<dlg->paraList[8]<<dlg->paraList[9]<<dlg->paraList[10];
            paraL = list;
            proIndex = 2;
        }
    }
    if(tag==3){
        QWParaInput4 *dlg=new QWParaInput4(this);
        Qt::WindowFlags flags=dlg->windowFlags();
        dlg->setWindowFlags(flags|Qt::MSWindowsFixedSizeDialogHint);
        int ret=dlg->exec();
        if(ret==QDialog::Accepted)
        {
            QList<float> list;
            list<<dlg->paraList[0]<<dlg->paraList[1]<<dlg->paraList[2]<<dlg->paraList[3]<<dlg->paraList[4]<<dlg->paraList[5]<<dlg->paraList[6]<<dlg->paraList[7]<<dlg->paraList[8]<<dlg->paraList[9];
            paraL = list;
            proIndex = 3;
        }
    }
    if(tag==4){
        QWParaInput5 *dlg=new QWParaInput5(this);
        Qt::WindowFlags flags=dlg->windowFlags();
        dlg->setWindowFlags(flags|Qt::MSWindowsFixedSizeDialogHint);
        int ret=dlg->exec();
        if(ret==QDialog::Accepted)
        {
            QList<float> list;
            list<<dlg->paraList[0]<<dlg->paraList[1]<<dlg->paraList[2]<<dlg->paraList[3]<<dlg->paraList[4]<<dlg->paraList[5]<<dlg->paraList[6]<<dlg->paraList[7]<<dlg->paraList[8]<<dlg->paraList[9]<<dlg->paraList[10]<<dlg->paraList[11]<<dlg->paraList[12];
            paraL = list;
            proIndex = 4;
        }
    }

}


void QWCalSoftware::on_pushButton_3_clicked()
{
    tag1 = 1;
    imageA = QImage(800, 600, QImage::Format_RGB32);
    imageB = QImage(800, 600, QImage::Format_RGB32);
    imageC = QImage(800, 600, QImage::Format_RGB32);
    paintScatter(100,imageA,imageB,imageC);
    QPixmap pix;
    pix = QPixmap::fromImage(imageA);
    label->setPixmap(pix);
    label->setScaledContents(true);
    QPixmap pix1;
    pix1 = QPixmap::fromImage(imageB);
    label1->setPixmap(pix1);
    label1->setScaledContents(true); //令图片显示在label中
}

void QWCalSoftware::on_horizontalSlider_valueChanged(int value)
{
    num = value;
    fLabCurFile->setText("当前荷载步："+QString::number(num));
    if(tag1=1)
    {
        paintScatter(value,imageA,imageB,imageC);
        QPixmap pix;
        pix = QPixmap::fromImage(imageA);
        label->setPixmap(pix);
        label->setScaledContents(true);
        if(tag2==0)
        {
            QPixmap pix1;
            pix1 = QPixmap::fromImage(imageB);
            label1->setPixmap(pix1);
            label1->setScaledContents(true);
        }
        else if(tag2==1)
        {
            QPixmap pix1;
            pix1 = QPixmap::fromImage(imageC);
            label1->setPixmap(pix1);
            label1->setScaledContents(true);
        }
    } //value改变时，更换图片
}


void QWCalSoftware::on_pushButton_2_clicked()
{
    if(proIndex==0)calGMPPD();
    if(proIndex==1)calEdgeDmg();
    if(proIndex==2)calCtDmg();
    if(proIndex==3)calLBoard(); //根据选择算例不同进行计算
}


void QWCalSoftware::on_radioButton_clicked(bool checked)
{
    if(checked)
    {
        tag2=1;
        QPixmap pix;
        pix = QPixmap::fromImage(imageC);
        label1->setPixmap(pix);
        label1->setScaledContents(true);
    }
    else if(!checked)
    {
        tag2=0;
        QPixmap pix;
        pix = QPixmap::fromImage(imageB);
        label1->setPixmap(pix);
        label1->setScaledContents(true);
    }
}

