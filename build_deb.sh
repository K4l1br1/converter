#!/bin/bash

# Скрипт для сборки deb пакета

set -e

# Цвета для вывода
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${GREEN}=== Сборка deb пакета unit-converter ===${NC}"

# Очистка предыдущих сборок
echo -e "${YELLOW}Очистка предыдущих сборок...${NC}"
make clean
rm -rf debian/usr
rm -f *.deb

# Компиляция программы
echo -e "${YELLOW}Компиляция программы...${NC}"
make

# Создание структуры директорий для пакета
echo -e "${YELLOW}Создание структуры пакета...${NC}"                
mkdir -p debian/DEBIAN          
mkdir -p debian/usr/bin
chmod 755 debian/DEBIAN

# Установка файлов
echo -e "${YELLOW}Установка файлов...${NC}"
make install DESTDIR=$(pwd)/debian PREFIX=/usr

# Сборка deb пакета
echo -e "${YELLOW}Сборка deb пакета...${NC}"
chmod 755 debian
dpkg-deb --build debian unit-converter_1.0.0_amd64.deb

# Проверка пакета
if [ -f unit-converter_1.0.0_amd64.deb ]; then
    echo -e "${GREEN}✓ Пакет успешно создан: unit-converter_1.0.0_amd64.deb${NC}"
    echo -e "${YELLOW}Информация о пакете:${NC}"
    dpkg-deb -I unit-converter_1.0.0_amd64.deb
    echo ""
    echo -e "${YELLOW}Содержимое пакета:${NC}"
    dpkg-deb -c unit-converter_1.0.0_amd64.deb
else
    echo -e "${RED}✗ Ошибка при создании пакета${NC}"
    exit 1
fi

