#include "greetingform.hpp"
#include "ui_greetingform.h"

GreetingForm::GreetingForm(QWidget *parent) : QWidget(parent), ui(new Ui::GreetingForm) {
    ui->setupUi(this);
    
    // Программное соединение сигналов и слотов (критическое требование)
    connect(ui->pushButton, &QPushButton::clicked, this, &GreetingForm::onButtonClicked);
}

GreetingForm::~GreetingForm() {
    delete ui;
}

void GreetingForm::onButtonClicked() {
    QString text = ui->lineEdit->text();
    if (text.isEmpty()) {
        ui->label->setText("Введите текст!");
    } else {
        ui->label->setText("Привет, " + text + "!");
    }
}
