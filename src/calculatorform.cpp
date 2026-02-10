#include "calculatorform.hpp"
#include "ui_calculatorform.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include <cmath>

CalculatorForm::CalculatorForm(QWidget *parent) : QWidget(parent), ui(new Ui::CalculatorForm) {
    ui->setupUi(this);
    
    // Установка валидации для полей ввода
    QDoubleValidator *validator1 = new QDoubleValidator(this);
    validator1->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_num1->setValidator(validator1);
    
    QDoubleValidator *validator2 = new QDoubleValidator(this);
    validator2->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_num2->setValidator(validator2);
    
    // Программное соединение сигналов и слотов
    connect(ui->pushButton_add, &QPushButton::clicked, this, &CalculatorForm::onAddClicked);
    connect(ui->pushButton_subtract, &QPushButton::clicked, this, &CalculatorForm::onSubtractClicked);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &CalculatorForm::onMultiplyClicked);
    connect(ui->pushButton_divide, &QPushButton::clicked, this, &CalculatorForm::onDivideClicked);
    connect(ui->pushButton_remainder, &QPushButton::clicked, this, &CalculatorForm::onRemainderClicked);
    
    // При изменении полей ввода очищаем результат и обновляем состояние кнопок
    connect(ui->lineEdit_num1, &QLineEdit::textChanged, this, &CalculatorForm::onInputChanged);
    connect(ui->lineEdit_num2, &QLineEdit::textChanged, this, &CalculatorForm::onInputChanged);
    
    // Начальное состояние кнопок
    updateButtonStates();
}

CalculatorForm::~CalculatorForm() {
    delete ui;
}

void CalculatorForm::onAddClicked() {
    double num1 = getFirstNumber();
    double num2 = getSecondNumber();
    double result = num1 + num2;
    setResult(QString::number(result));
}

void CalculatorForm::onSubtractClicked() {
    double num1 = getFirstNumber();
    double num2 = getSecondNumber();
    double result = num1 - num2;
    setResult(QString::number(result));
}

void CalculatorForm::onMultiplyClicked() {
    double num1 = getFirstNumber();
    double num2 = getSecondNumber();
    double result = num1 * num2;
    setResult(QString::number(result));
}

void CalculatorForm::onDivideClicked() {
    double num1 = getFirstNumber();
    double num2 = getSecondNumber();
    
    // Обработка деления на ноль с учетом погрешности
    if (std::abs(num2) < 1e-10) {
        setResult("Ошибка, деление на ноль невозможно");
        return;
    }
    
    double result = num1 / num2;
    setResult(QString::number(result));
}

void CalculatorForm::onRemainderClicked() {
    double num1 = getFirstNumber();
    double num2 = getSecondNumber();
    
    // Обработка остатка от деления на ноль с учетом погрешности
    if (std::abs(num2) < 1e-10) {
        QMessageBox::critical(this, "Ошибка", "Деление на ноль невозможно!");
        setResult("Ошибка, деление на ноль невозможно");
        return;
    }
    
    // Используем fmod для вычисления остатка от деления
    double result = std::fmod(num1, num2);
    setResult(QString::number(result));
}

void CalculatorForm::onInputChanged() {
    // При изменении данных очищаем результат
    clearResult();
    
    // Обновляем состояние кнопок
    updateButtonStates();
}

void CalculatorForm::updateButtonStates() {
    // Кнопки доступны только если оба поля заполнены (критическое требование)
    bool hasInput = !ui->lineEdit_num1->text().isEmpty() && 
                    !ui->lineEdit_num2->text().isEmpty();
    
    ui->pushButton_add->setEnabled(hasInput);
    ui->pushButton_subtract->setEnabled(hasInput);
    ui->pushButton_multiply->setEnabled(hasInput);
    ui->pushButton_divide->setEnabled(hasInput);
    ui->pushButton_remainder->setEnabled(hasInput);
}

void CalculatorForm::clearResult() {
    ui->lineEdit_result->clear();
}

double CalculatorForm::getFirstNumber() const {
    return ui->lineEdit_num1->text().toDouble();
}

double CalculatorForm::getSecondNumber() const {
    return ui->lineEdit_num2->text().toDouble();
}

void CalculatorForm::setResult(const QString &text) {
    ui->lineEdit_result->setText(text);
}
