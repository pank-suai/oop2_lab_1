#include <QApplication>
#include <QTabWidget>
#include "greetingform.hpp"
#include "calculatorform.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Главное окно с вкладками для двух форм
    QTabWidget mainWindow;
    mainWindow.setWindowTitle("Панков В.Д., группа М412");
    mainWindow.resize(600, 400);
    
    // Форма приветствия (Часть 1)
    GreetingForm *greetingForm = new GreetingForm();
    mainWindow.addTab(greetingForm, "Форма приветствия");
    
    // Калькулятор (Часть 2)
    CalculatorForm *calculatorForm = new CalculatorForm();
    mainWindow.addTab(calculatorForm, "Калькулятор");
    
    mainWindow.show();
    
    return app.exec();
}
