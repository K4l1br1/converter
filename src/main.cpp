#include <iostream>
#include <string>
#include <limits>
#include "converter.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\\n');
}

int main() {
    UnitConverter converter;
    
    cout << "========================================" << endl;
    cout << "  КОНВЕРТЕР ЕДИНИЦ ИЗМЕРЕНИЯ" << endl;
    cout << "========================================" << endl;
    
    while (true) {
        converter.displayMenu();
        
        int choice;
        cout << "\\nВыберите тип конвертации (0 для выхода): ";
        cin >> choice;
        
        if (cin.fail()) {
            clearInput();
            cout << "Ошибка ввода! Попробуйте снова." << endl;
            continue;
        }
        
        if (choice == 0) {
            cout << "До свидания!" << endl;
            break;
        }
        
        UnitConverter::ConversionType type;
        
        switch (choice) {
            case 1:
                type = UnitConverter::ConversionType::DISTANCE;
                break;
            case 2:
                type = UnitConverter::ConversionType::WEIGHT;
                break;
            case 3:
                type = UnitConverter::ConversionType::TEMPERATURE;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                continue;
        }
        
        cout << "\\nДоступные единицы: " << converter.getAvailableUnits(type) << endl;
        
        string fromUnit, toUnit;
        double value;
        
        cout << "Введите исходную единицу: ";
        cin >> fromUnit;
        
        cout << "Введите целевую единицу: ";
        cin >> toUnit;
        
        cout << "Введите значение: ";
        cin >> value;
        
        if (cin.fail()) {
            clearInput();
            cout << "Ошибка ввода значения!" << endl;
            continue;
        }
        
        try {
            double result = converter.convert(type, fromUnit, toUnit, value);
            cout << "\\n>>> Результат: " << value << " " << fromUnit 
                 << " = " << result << " " << toUnit << endl << endl;
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl << endl;
        }
    }
    
    return 0;
}
