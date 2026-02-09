#pragma once

#include <QWidget>

namespace Ui {
class GreetingForm;
}

// Форма приветствия с QLineEdit, QPushButton и QLabel
class GreetingForm : public QWidget {
    Q_OBJECT

public:
    explicit GreetingForm(QWidget *parent = nullptr);
    ~GreetingForm();

private slots:
    void onButtonClicked();

private:
    Ui::GreetingForm *ui;
};
