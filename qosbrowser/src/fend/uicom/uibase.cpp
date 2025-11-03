#include "uibase.h"
#include "ui_uibase.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QKeyEvent>

UiBase::UiBase(QWidget *parent)
    : QDialog(parent), m_ui(new Ui::UiBase)
{
    m_ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window); // 去掉默认标题栏

    setLogo(":/static/img/icontt.ico"); // 图标
    addCloseButton(":/static/img/close1.png", ":/static/img/close2.png");
    setAllButtonSize();                    // 同一按钮大小
    m_ui->labelLogo->setFixedSize(40, 40); // 设置图标大小
}

UiBase::~UiBase() {
    delete m_ui;
}

void UiBase::setTitle(const QString &title)
{
    m_ui->labelTitle->setText(title);
}

void UiBase::setLogo(const QString &path)
{
    m_ui->labelLogo->setStyleSheet(
        QString("border-image:url(\"%1\");").arg(path));
}

void UiBase::addMinButton(const QString &path, const QString &hoverPath)
{
    UiPushButton *btn = addButton(path, hoverPath);
    connect(btn, &UiPushButton::clicked, this, &UiBase::showMinimized);
}

void UiBase::addMaxButton(const QString &maxPath,
                              const QString &maxPathHover,
                              const QString &normalPath,
                              const QString &normalPathHover)
{
    UiPushButton *btn = addButton(maxPath, maxPathHover);

    // 设置右上角按钮icon
    auto funcImg = [=]() {
    isMaximized() ? setButtonImage(btn, normalPath, normalPathHover)
                      : setButtonImage(btn, maxPath, maxPathHover);
    };
    auto funcShow = [=]() {
        isMaximized() ? showNormal() : showMaximized();
        funcImg();
    };

    connect(btn, &UiPushButton::clicked, this, funcShow);
    funcImg();
}

UiPushButton *UiBase::addButton(const QString &path, const QString &hoverPath)
{
    UiPushButton *btn = new UiPushButton;
    btn->setFixedSize(m_sz, m_sz);
    setButtonImage(btn, path, hoverPath);
    addWidget(btn);
    return btn;
}

void UiBase::setButtonImage(UiPushButton *btn, const QString &path, const QString &hoverPath)
{
    btn->setStyleSheet(QString("QPushButton{border-image: url(\"%1\");}"
                               "QPushButton:hover{border-image: url(\"%2\");}")
                           .arg(path, hoverPath));
}

void UiBase::setAllButtonSize(int w)
{
    QList<UiPushButton *> btnList =
        m_ui->frameTitle->findChildren<UiPushButton *>();
    for (auto *btn : btnList) {
        btn->setFixedSize(w, w); // 设置宽高
    }
    m_sz = w;
}

void UiBase::setKeyDisabled()
{
    installEventFilter(this);
}

void UiBase::addTitleLine(int w)
{
    QLabel* label = new QLabel;
    label->setFixedSize(w ,15);
    addWidget(label);
}


void UiBase::mousePressEvent(QMouseEvent *event)
{
    // 获取单击时的起始位置
    if (event->button() == Qt::LeftButton) {
        m_start = event->pos(); // 返回相对于父窗口坐标原点的位置
    }
    QDialog::mousePressEvent(event); // 在最后要反调父函数
}


void UiBase::mouseMoveEvent(QMouseEvent *event)
{
    // 单击长按可拖动窗口
    if (event->buttons() & Qt::LeftButton) {
        QPoint targetPos = event->pos() - m_start + pos(); // 目标位置
        this->move(targetPos);                             // 窗口移动
    }
    QDialog::mouseMoveEvent(event); // 在最后要反调父函数
}

bool UiBase::eventFilter(QObject *obj, QEvent *event)
{

    UiBase *pDialog = qobject_cast<UiBase *>(obj);

    // 如果转换成功并且事件的类型是键盘按下事件
    if (pDialog && event->type() == QEvent::KeyPress) {
        QKeyEvent *pKeyEvent = static_cast<QKeyEvent*>(event);

        // 回车键、Esc键或者另一个回车键（Qt::Key_Enter）进行拦截
        if (pKeyEvent->key() == Qt::Key_Return
            || pKeyEvent->key() == Qt::Key_Escape
            || pKeyEvent->key() == Qt::Key_Enter) {
            return true;
        }
    }

    // 如果不是上述情况，则调用父类的事件过滤器处理函数
    return QObject::eventFilter(obj, event);
}

QWidget *UiBase::body()
{
    return m_ui->widgetBody;
}

void UiBase::addCloseButton(const QString &path, const QString &hoverPath)
{
    setButtonImage(m_ui->btnClose, path, hoverPath);
    m_ui->horizontalLayout->addWidget(m_ui->btnClose);
    connect(m_ui->btnClose, &UiPushButton::clicked, this, &UiBase::reject);
}

void UiBase::addWidget(QWidget *w)
{
    int i = m_ui->horizontalLayout->indexOf(m_ui->btnClose);
    m_ui->horizontalLayout->insertWidget(i, w);
}



void UiBase::on_btnClose_clicked()
{
    return;
}

