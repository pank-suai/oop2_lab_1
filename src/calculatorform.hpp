#pragma once

#include <QWidget>

namespace Ui {
class CalculatorForm;
}

// Форма калькулятора с поддержкой всех операций
class CalculatorForm : public QWidget {
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = nullptr);
    ~CalculatorForm();

private slots:
    void onAddClicked();
    void onSubtractClicked();
    void onMultiplyClicked();
    void onDivideClicked();
    void onRemainderClicked();
    void onInputChanged();

private:
    void updateButtonStates();
    void clearResult();
    double getFirstNumber() const;
    double getSecondNumber() const;
    void setResult(const QString &text);
    
    Ui::CalculatorForm *ui;
};
