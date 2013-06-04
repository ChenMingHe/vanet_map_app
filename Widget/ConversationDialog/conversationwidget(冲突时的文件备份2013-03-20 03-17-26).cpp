#include "conversationwidget.h"
#include "ui_conversationwidget.h"

ConversationWidget::ConversationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConversationWidget),
    talkTo("")
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    ui->groupBox->layout()->setMargin(0);
    ui->gridLayout_3->setMargin(0);
}

ConversationWidget::~ConversationWidget()
{
    delete ui;
}

void ConversationWidget::handleRequest(Operations::Type type, const QString &userName, const QString &text)
{
    if (type == Operations::APPEND_TEXT) {
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")
                                + " " + userName
                                + "\n  > " + text);
    }
}

void ConversationWidget::talkToUser(QString name)
{
    if (name != "[Me]") {
        ui->groupBox_userName->setTitle("To " + name);
        talkTo = name;
    }
}

void ConversationWidget::clearTextEdit()
{
    ui->errorInfoLabel->clear();
}

void ConversationWidget::on_sendButton_clicked()
{
    if (ui->textEdit->toPlainText().isEmpty()) {
        ui->errorInfoLabel->setText("Empty Message");
        QTimer::singleShot(1000, this, SLOT(clearTextEdit()));
        return;
    }
    if (talkTo.isEmpty()) {
        ui->errorInfoLabel->setText("Unknown User");
        QTimer::singleShot(1000, this, SLOT(clearTextEdit()));
        return;
    }

    QString msg;
    msg = LocalLocationInfomation::info().getLocalUserName() +
            " [100] " + " A " +
            ui->textEdit->toPlainText();
    UdpSender::socket().sendData("A " + talkTo + " " + msg + " \n");

    ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss") + " talk to :" +
                            talkTo + "\n>> " + ui->textEdit->toPlainText());
    ui->textEdit->clear();
    LogDebug(0) << msg;
}


void ConversationWidget::on_fileSelectButton_clicked()
{
    if (talkTo.isEmpty()) {
        ui->errorInfoLabel->setText("Unknown User");
        QTimer::singleShot(1000, this, SLOT(clearTextEdit()));
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this);
    TcpSender *sender = new TcpSender(this);
    sender->sendFile(talkTo, fileName);
    ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss") + " [Me] :\n>> "
                            + "send file : " + fileName);
}

