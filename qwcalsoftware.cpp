#pragma execution_character_set("utf-8")

#include "qwcalsoftware.h"
#include "ui_qwcalsoftware.h"
#include "iconhelper.h"
#include "quihelper.h"
#include "information.h"


QWCalSoftware::QWCalSoftware(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWCalSoftware)
{
    ui->setupUi(this);
    this->initForm();
    this->initStyle();
    this->initLeftCons();
    this->initLeftCal();
    this->initLeftShow();

}

QWCalSoftware::~QWCalSoftware()
{
    delete ui;
}

void QWCalSoftware::getQssColor(const QString &qss, const QString &flag, QString &color)
{
    int index = qss.indexOf(flag);
    if (index >= 0) {
        color = qss.mid(index + flag.length(), 7);
    }
}

void QWCalSoftware::getQssColor(const QString &qss, QString &textColor, QString &panelColor, QString &borderColor, QString &normalColorStart, QString &normalColorEnd, QString &darkColorStart, QString &darkColorEnd, QString &highColor)
{
    getQssColor(qss, "TextColor:", textColor);
    getQssColor(qss, "PanelColor:", panelColor);
    getQssColor(qss, "BorderColor:", borderColor);
    getQssColor(qss, "NormalColorStart:", normalColorStart);
    getQssColor(qss, "NormalColorEnd:", normalColorEnd);
    getQssColor(qss, "DarkColorStart:", darkColorStart);
    getQssColor(qss, "DarkColorEnd:", darkColorEnd);
    getQssColor(qss, "HighColor:", highColor);
}

void QWCalSoftware::initForm()
{
    //设置无边框
    QUIHelper::setFramelessForm(this);
//    setWindowState(Qt::WindowMaximized);
    //设置图标
    IconHelper::setIcon(ui->labIco, 0xf073, 30);
    IconHelper::setIcon(ui->btnMenu_Min, 0xf068);
    IconHelper::setIcon(ui->btnMenu_Max, 0xf067);
    IconHelper::setIcon(ui->btnMenu_Close, 0xf00d);

    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");

    QFont font;
    font.setPixelSize(20);
    ui->labTitle->setFont(font);
    ui->labTitle->setText("固体连续-非连续变形统一模拟软件");
    this->setWindowTitle(ui->labTitle->text());

    ui->stackedWidget->setStyleSheet("QLabel{font:12px;}");

    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QAbstractButton *> btns = ui->widgetTop->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btn, btns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnCons->click();

    ui->widgetLeftCons->setProperty("flag", "left");
    ui->widgetLeftCal->setProperty("flag", "left");
    ui->widgetLeftShow->setProperty("flag", "left");
    ui->page1->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));
    ui->page2->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));
    ui->page3->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));


}

void QWCalSoftware::initStyle()
{
    //加载样式表
    QString qss;
    QFile file(":/qss/blacksoft.css");
    if (file.open(QFile::ReadOnly)) {
        qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(paletteColor));
        qApp->setStyleSheet(qss);
        file.close();
    }

    //先从样式表中取出对应的颜色
    QString textColor, panelColor, borderColor, normalColorStart, normalColorEnd, darkColorStart, darkColorEnd, highColor;
    getQssColor(qss, textColor, panelColor, borderColor, normalColorStart, normalColorEnd, darkColorStart, darkColorEnd, highColor);

    //将对应颜色设置到控件
    this->borderColor = highColor;
    this->normalBgColor = normalColorStart;
    this->darkBgColor = panelColor;
    this->normalTextColor = textColor;
    this->darkTextColor = normalTextColor;
}

void QWCalSoftware::buttonClick()
{
    QAbstractButton *b = (QAbstractButton *)sender();
    QString name = b->text();

    QList<QAbstractButton *> btns = ui->widgetTop->findChildren<QAbstractButton *>();
    foreach (QAbstractButton *btn, btns) {
        btn->setChecked(btn == b);
    }
    if (name == "结构建模") {
        ui->stackedWidget->setCurrentIndex(0);
        b->setEnabled(false); // 禁用点击的按钮
    }
    else if (name == "结构计算") {
        //ui->stackedWidget->setCurrentIndex(1);
        //ui->labPcs->setText("");
    }
    else if (name == "后处理") {
        //ui->stackedWidget->setCurrentIndex(2);
        //ui->Slider->setValue(1);
    }
}

void QWCalSoftware::initLeftCons()
{
    iconsCons << 0xf18e << 0xf18e << 0xf18e << 0xf18e;
    btnsCons << ui->tbtnCons1 << ui->tbtnCons2 << ui->tbtnCons3 << ui->tbtnCons4;

    int count = btnsCons.count();
    for (int i = 0; i < count; ++i) {
        QToolButton *btn = (QToolButton *)btnsCons.at(i);
        btn->setCheckable(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(leftConsClick()));
    }

    IconHelper::StyleColor styleColor;
    styleColor.position = "left";
    styleColor.iconSize = 18;
    styleColor.iconWidth = 35;
    styleColor.iconHeight = 25;
    styleColor.borderWidth = 4;
    styleColor.borderColor = borderColor;
    styleColor.setColor(normalBgColor, normalTextColor, darkBgColor, darkTextColor);
    IconHelper::setStyle(ui->widgetLeftCons, btnsCons, iconsCons, styleColor);
    ui->tbtnCons1->click();

    QFont font;
    font.setPointSize(7);
    QList<QLabel *> labs = ui->stackedWidgetIn->findChildren<QLabel *>();
    foreach (QLabel *lab, labs) {
        lab->setFont(font);
    }
}

void QWCalSoftware::initLeftCal()
{
    iconsCal << 0xf039 << 0xf0da;
    btnsCal << ui->tbtnCal1 << ui->tbtnCal2;

    QToolButton *btn = (QToolButton *)btnsCal.at(0);
    btn->setCheckable(true);
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(leftRoadClick()));

    btn = (QToolButton *)btnsCal.at(1);
    btn->setCheckable(true);
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(leftCalClick()));

    IconHelper::StyleColor styleColor;
    styleColor.position = "left";
    styleColor.iconSize = 20;
    styleColor.iconWidth = 35;
    styleColor.iconHeight = 25;
    styleColor.borderWidth = 4;
    styleColor.borderColor = borderColor;
    styleColor.setColor(normalBgColor, normalTextColor, darkBgColor, darkTextColor);
    IconHelper::setStyle(ui->widgetLeftCal, btnsCal, iconsCal, styleColor);
}

void QWCalSoftware::initLeftShow()
{
    iconsShow << 0xf0a4 << 0xf25a << 0xf16e;
    btnsShow << ui->tbtnShow1 << ui->tbtnShow2  << ui->tbtnShow3 << ui->tbtnShow4;

    int count = btnsShow.count();
    for (int i = 0; i < count; ++i) {
        QToolButton *btn = (QToolButton *)btnsShow.at(i);
        btn->setCheckable(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(leftShowClick()));
    }

    IconHelper::StyleColor styleColor;
    styleColor.position = "left";
    styleColor.iconSize = 20;
    styleColor.iconWidth = 35;
    styleColor.iconHeight = 25;
    styleColor.borderWidth = 4;
    styleColor.borderColor = borderColor;
    styleColor.setColor(normalBgColor, normalTextColor, darkBgColor, darkTextColor);
    IconHelper::setStyle(ui->widgetLeftShow, btnsCal, iconsCal, styleColor);

    ui->Slider->setValue(50);
}

void QWCalSoftware::leftConsClick()
{
    QAbstractButton *b = (QAbstractButton *)sender();
    QString name = b->text();

    int count = btnsCons.count();
    std::cout << count;
    for (int i = 0; i < count; ++i) {
        QAbstractButton *btn = btnsCons.at(i);
        btn->setChecked(btn == b);
    }

    if (name == "巴西劈裂试验") {
        proIndex = 0;
        ui->stackedWidgetIn->setCurrentIndex(proIndex);
    } else if (name == "单边缺口试件裂纹扩展试验") {
        proIndex = 1;
        ui->stackedWidgetIn->setCurrentIndex(proIndex);
    } else if (name == "中心缺口试件裂纹扩展试验") {
        proIndex = 2;
        ui->stackedWidgetIn->setCurrentIndex(proIndex);
    } else if (name == "L板断裂试验") {
        proIndex = 3;
        ui->stackedWidgetIn->setCurrentIndex(proIndex);
    }
}

void QWCalSoftware::leftRoadClick()
{
    QToolButton *b = (QToolButton *)sender();

    int count = btnsCal.count();
    for (int i = 0; i < count; ++i) {
        QAbstractButton *btn = btnsCal.at(i);
        btn->setChecked(btn == b);
    }

    filePath = QFileDialog::getExistingDirectory(this, "选择vtk文件存储路径", "");
    std::cout << "#######################";
    qDebug() << filePath << endl;
    if(filePath!= ""){
        b->setEnabled(false); // 禁用点击的按钮
        IfPathChoose = true;
    }

}

void QWCalSoftware::leftCalClick()
{
    QToolButton *b = (QToolButton *)sender();
    if(IfPathChoose){
        int count = btnsCal.count();
        for (int i = 0; i < count; ++i) {
            QAbstractButton *btn = btnsCal.at(i);
            btn->setChecked(btn == b);
        }
        switch (proIndex)
        {
        case 0:
            calGMPPD();
            break;
        case 1:
            calEdgeDmg();
            break;
        case 2:
            calCtDmg();
            break;
        case 3:
            calLBoard();
            break;
        }
    }

}

void QWCalSoftware::leftShowClick()//未完成
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();
    int count = btnsShow.count();
    for (int i = 0; i < count; ++i) {
        QAbstractButton *btn = btnsShow.at(i);
        btn->setChecked(btn == b);
    }
    QPixmap pix;
    QGraphicsScene *scn = new QGraphicsScene;

    if (name == "x方向位移图") {
        pix = QPixmap::fromImage(img2);
    } else if (name == "y方向位移图") {
        pix = QPixmap::fromImage(img3);
    } else if (name == "结构损伤散点图") {
        pix = QPixmap::fromImage(img1);
    }

    QGraphicsPixmapItem *p = scn->addPixmap(pix);
    ui->View->setScene(scn);
    ui->View->fitInView((QGraphicsItem*)p, Qt::IgnoreAspectRatio);
    ui->View->show();

}

void QWCalSoftware::calGMPPD()
{
//    double start = GetTickCount64();

    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paras[7];
    //y方向点个数
//    const int ndivy = ndivx;
    const int ndivy = paras[8];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx;
    //总荷载步数
    const int nt = foot;
//    const int nt = 100;
    // 速度边界
    double vbd = paras[9];
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
    double cracklength = paras[5];
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
//    double thick = min(dx, dy);
    double thick = paras[6];
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
    double rho = paras[2];
    //弹性模量
//    double emod = 192.0e9;
    double emod = paras[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
//    double pratio = 0.3;
    double pratio = paras[1];
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


    QProgressDialog progressWindow;
    progressWindow.setWindowTitle("计算进度");
    progressWindow.setLabelText("正在计算...");
    progressWindow.setRange(0, foot); // 设置进度条范围
    progressWindow.setCancelButton(NULL);

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
        std::string filename = filePath.toStdString() + "/GMPPD_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename, ios::out);
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
        progressWindow.setValue(tt);
        QApplication::processEvents(); // 保持 UI 响应
    }
//    double  end = GetTickCount64();
    progressWindow.close();
    EndForCal();
    return;
}

void QWCalSoftware::calEdgeDmg()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paras[7];
    //y方向点个数
    const int ndivy = paras[8];
//    const int ndivy = ndivx;
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    //总荷载步数
    const int nt = foot;
//    const int nt = 100;
    // 速度边界
    double vbd = paras[9];
//    double vbd = 30;
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paras[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paras[4];
//    double width = 0.5;
    w = width;
    //初始裂纹长度
    double cracklength = paras[6];
//    double cracklength = 0.5 * length;
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
    double thick = paras[5];
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
    double rho = paras[2];
    //弹性模量
    //    double emod = 192.0e9;
    double emod = paras[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
    //    double pratio = 0.3;
    double pratio = paras[1];
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
    QProgressDialog progressWindow;
    progressWindow.setWindowTitle("计算进度");
    progressWindow.setLabelText("正在计算...");
    progressWindow.setRange(0, foot); // 设置进度条范围
    progressWindow.setCancelButton(NULL);
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
        std::string filename = filePath.toStdString()+ "/EdgeDmg_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename, ios::out);
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
        progressWindow.setValue(tt);
        QApplication::processEvents(); // 保持 UI 响应
    }
    progressWindow.close();
    EndForCal();
}

void QWCalSoftware::calCtDmg()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paras[7];
    //y方向点个数
    const int ndivy = paras[8];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层
    const int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    //总荷载步数
    const int nt = foot;
//    const int nt = 100;
    // 速度边界
    double vbd = paras[9];
//    double vbd = 30;
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paras[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paras[4];
//    double width = 0.5;
    w = width;
    //初始裂纹长度
    double cracklength = paras[6];
//    double cracklength = 0.5 * length;
    //物质点间距
    double dx = length / ndivx;
    //物质点间距
    double dy = width / ndivy;
    //试件厚度
    double thick = paras[5];
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
    double rho = paras[2];
    //弹性模量
    //    double emod = 192.0e9;
    double emod = paras[0];
    //临界能量释放率
    double G0 = 1000.0;
    //泊松比
    //    double pratio = 0.3;
    double pratio = paras[1];
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
    QProgressDialog progressWindow;
    progressWindow.setWindowTitle("计算进度");
    progressWindow.setLabelText("正在计算...");
    progressWindow.setRange(0, foot); // 设置进度条范围
    progressWindow.setCancelButton(NULL);
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
        std::string filename = filePath.toStdString() + "/CtDmg_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename, ios::out);
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
        progressWindow.setValue(tt);
        QApplication::processEvents(); // 保持 UI 响应
    }
    progressWindow.close();
    EndForCal();
    return;
}

void QWCalSoftware::calLBoard()
{
    //物理和计算参数设定
    //x方向物质点数,必须偶数
    const int ndivx = paras[6];
    //y方向点个数
    const int ndivy = paras[7];
    //边界层厚度
    const int nbnd = 3;
    //总的点个数，内部点加虚拟边界层，L板总的点个数需要在建立物质点模型时计算
    int totnode = ndivx * ndivy + 2 * nbnd * ndivx ;
    // 速度边界
    double vbd = paras[8];
    //物质点的最大邻域粒子数
    const int maxfam = 300;
    //试件长度
    double length = paras[3];
//    double length = 0.5;
    l = length;
    //试件宽度
    double width = paras[4];
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
    double thick = paras[5];
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
    double rho = paras[2];
//    double rho = 2265.0;
    //弹性模量
    double emod = paras[0];
//    double emod = 25.85e9;
    //临界能量释放率
    double G0 = 65.0;
    //泊松比 0.18，键型可以么？
    double pratio = paras[1];
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
    const int nt = foot;
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

    QProgressDialog progressWindow;
    progressWindow.setWindowTitle("计算进度");
    progressWindow.setLabelText("正在计算...");
    progressWindow.setRange(0, foot); // 设置进度条范围
    progressWindow.setCancelButton(NULL);
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
        std::string filename = filePath.toStdString() + "/LBoard_";
        filename = filename + std::to_string(tt) + ".vtk";
        std::ofstream outfile;
        outfile.open(filename, ios::out);
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
        progressWindow.setValue(tt);
        QApplication::processEvents(); // 保持 UI 响应
    }
    progressWindow.close();
    EndForCal();
    return;
}

/*计算步骤结尾自动跳转至后处理*/
void QWCalSoftware::EndForCal()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Slider->setValue(1);
}

void QWCalSoftware::paintScatter(int n) //画图函数
{

    QString str1;
    switch (proIndex)
    {
    case 0:
        str1="/GMPPD_";
        break;
    case 1:
        str1="/EdgeDmg_";
        break;
    case 2:
        str1="/CtDmg_";
        break;
    case 3:
        str1="/LBoard_";
        break;
    }
    QString str2=QString::number(n);
    QString str3=".vtk";
    QString filename = filePath+str1+str2+str3;
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
    } //寻找disp位移值

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

    //以下为绘图内容
    QColor backColor = qRgb(255, 255, 255);
    QImage image1 = QImage(800, 600, QImage::Format_RGB32);
    image1.fill(backColor);
    QImage image2 = QImage(800, 600, QImage::Format_RGB32);
    image2.fill(backColor);
    QImage image3 = QImage(800, 600, QImage::Format_RGB32);
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
    QColor color;
    QRect section;

    qreal dmgMax = *max_element(dmg.begin(), dmg.end());
    qreal dmgMin = *min_element(dmg.begin(), dmg.end());
    if (dmgMax==0)dmgMax=1;
    int gray; //设置颜色映射变量

    for(int i = 0;i<x.size();i++)
    {
        gray = (dmg[i]-dmgMin)/(dmgMax-dmgMin)*255;
        if(gray >= 0 && gray <= 15)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color1);
        }
        else if(gray >= 16 && gray <= 31)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color2);
        }
        else if(gray >= 32 && gray <= 47)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color3);
        }
        else if(gray >= 48 && gray <= 63)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color4);
        }
        else if(gray >= 64 && gray <= 79)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color5);
        }
        else if(gray >= 80 && gray <= 95)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color6);
        }
        else if(gray >= 96 && gray <= 111)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color7);
        }
        else if(gray >= 112 && gray <= 127)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color8);
        }
        else if(gray >= 128 && gray <= 143)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color9);
        }
        else if(gray >= 144 && gray <= 159)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color10);
        }
        else if(gray >= 160 && gray <= 175)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color11);
        }
        else if(gray >= 176 && gray <= 191)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color12);
        }
        else if(gray >= 192 && gray <= 207)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color13);
        }
        else if(gray >= 208 && gray <= 223)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color14);
        }
        else if(gray >= 224 && gray <= 239)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color15);
        }
        else if(gray >= 240 && gray <= 255)
        {
            section.setRect(x[i]*l*1600+330,y[i]*w*1600+300,15,15);
            painter1.fillRect(section,color16);
        }
    } //画散点图

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

    img1 = image1; img2 = image2; img3 = image3;
}



void QWCalSoftware::on_btnLoad1_clicked()
{
    paras.clear();
    QString str = ui->txt1_1->text();
    paras.append(str.toFloat());

    str = ui->txt1_2->text();
    paras.append(str.toFloat());

    str = ui->txt1_3->text();
    paras.append(str.toFloat());

    str = ui->txt1_4->text();
    paras.append(str.toFloat());

    str = ui->txt1_5->text();
    paras.append(str.toFloat());

    str = ui->txt1_6->text();
    paras.append(str.toFloat());

    str = ui->txt1_7->text();
    paras.append(str.toFloat());

    str = ui->txt1_8->text();
    foot = str.toInt();

    str = ui->txt1_9->text();
    paras.append(str.toFloat());

    str = ui->txt1_10->text();
    paras.append(str.toFloat());

    str = ui->txt1_11->text();
    paras.append(str.toFloat());

    ui->Slider->setMaximum(foot);
    ui->stackedWidget->setCurrentIndex(1);
    ui->labPcs->setText("");
}


void QWCalSoftware::on_btnLoad2_clicked()
{
    paras.clear();
    QString str = ui->txt2_1->text();
    paras.append(str.toFloat());

    str = ui->txt2_2->text();
    paras.append(str.toFloat());

    str = ui->txt2_3->text();
    paras.append(str.toFloat());

    str = ui->txt2_4->text();
    paras.append(str.toFloat());

    str = ui->txt2_5->text();
    paras.append(str.toFloat());

    str = ui->txt2_6->text();
    paras.append(str.toFloat());

    str = ui->txt2_7->text();
    paras.append(str.toFloat());

    str = ui->txt2_8->text();
    foot = str.toInt();

    str = ui->txt2_9->text();
    paras.append(str.toFloat());

    str = ui->txt2_10->text();
    paras.append(str.toFloat());

    str = ui->txt2_11->text();
    paras.append(str.toFloat());

    ui->Slider->setMaximum(foot);
    ui->stackedWidget->setCurrentIndex(1);
    ui->labPcs->setText("");
}


void QWCalSoftware::on_btnLoad3_clicked()
{
    paras.clear();
    QString str = ui->txt3_1->text();
    paras.append(str.toFloat());

    str = ui->txt3_2->text();
    paras.append(str.toFloat());

    str = ui->txt3_3->text();
    paras.append(str.toFloat());

    str = ui->txt3_4->text();
    paras.append(str.toFloat());

    str = ui->txt3_5->text();
    paras.append(str.toFloat());

    str = ui->txt3_6->text();
    paras.append(str.toFloat());

    str = ui->txt3_7->text();
    paras.append(str.toFloat());

    str = ui->txt3_8->text();
    foot = str.toInt();

    str = ui->txt3_9->text();
    paras.append(str.toFloat());

    str = ui->txt3_10->text();
    paras.append(str.toFloat());

    str = ui->txt3_11->text();
    paras.append(str.toFloat());

    ui->Slider->setMaximum(foot);
    ui->stackedWidget->setCurrentIndex(1);
    ui->labPcs->setText("");
}


void QWCalSoftware::on_btnLoad4_clicked()
{
    paras.clear();
    QString str = ui->txt4_1->text();
    paras.append(str.toFloat());

    str = ui->txt4_2->text();
    paras.append(str.toFloat());

    str = ui->txt4_3->text();
    paras.append(str.toFloat());

    str = ui->txt4_4->text();
    paras.append(str.toFloat());

    str = ui->txt4_5->text();
    paras.append(str.toFloat());

    str = ui->txt4_6->text();
    paras.append(str.toFloat());

    str = ui->txt4_7->text();
    foot = str.toInt();

    str = ui->txt4_8->text();
    paras.append(str.toFloat());

    str = ui->txt4_9->text();
    paras.append(str.toFloat());

    str = ui->txt4_10->text();
    paras.append(str.toFloat());

    ui->Slider->setMaximum(foot);
    ui->stackedWidget->setCurrentIndex(1);
    ui->labPcs->setText("");
}


void QWCalSoftware::on_btnMenu_Min_clicked()
{
    showMinimized();
}


void QWCalSoftware::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(QUIHelper::getScreenRect());
    }

    this->setProperty("canMove", max);
    max = !max;
}


void QWCalSoftware::on_btnMenu_Close_clicked()
{
    close();
}


void QWCalSoftware::on_Slider_valueChanged(int value)//未完成
{
    num = value;
    ui->labFoot2->setText(QString::number(num));

    paintScatter(value);
    QPixmap pix;
    QGraphicsScene *scn = new QGraphicsScene;

//    QLabel labView = new QLabel(this);
//    labView->setAlignment(Qt::AlignCenter);
//    QRect loc = ui->graphicsView->geometry();
//    int xView = loc.x(), yView = loc.y(), wView = loc.width(), hView = loc.height();
//    labView->setGeometry(xView + wView/8, yView + hView/8, wView*0.75, hView*0.75);

    if(ui->tbtnShow1->isChecked())
    {
        pix = QPixmap::fromImage(img2);
//        labView->setPixmap(pix);
//        labView->setScaledContents(true);
    }else if(ui->tbtnShow2->isChecked()){
        pix = QPixmap::fromImage(img3);
//        labView->setPixmap(pix);
//        labView->setScaledContents(true);
    }else if(ui->tbtnShow3->isChecked()){
        pix = QPixmap::fromImage(img1);
//        labView->setPixmap(pix);
//        labView->setScaledContents(true);
    }

    QGraphicsPixmapItem *p = scn->addPixmap(pix);
    ui->View->setScene(scn);
    ui->View->fitInView((QGraphicsItem*)p, Qt::IgnoreAspectRatio);
    ui->View->show();

}

/*鼠标移动及界面调整大小*/

void QWCalSoftware::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        // Capture the initial position when mouse is pressed
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
    }
}

void QWCalSoftware::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton) {
        // Move the window when the mouse is moved while pressed
        move(event->globalPos() - m_dragPosition);
    }
}

void QWCalSoftware::on_tbtnShow4_clicked()
{
    QWCalSoftware *p = this;
    information *Information = new information(p, this);
    Information->show();
}

