#!/bin/bash

# Скрипт для сборки rpm пакета

set -e

# Цвета для вывода
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${GREEN}=== Сборка rpm пакета unit-converter ===${NC}"

# Очистка предыдущих сборок
echo -e "${YELLOW}Очистка предыдущих сборок...${NC}"
make clean
rm -f *.rpm

# Компиляция программы
echo -e "${YELLOW}Компиляция программы...${NC}"
make

# Проверка наличия rpmbuild
if ! command -v rpmbuild &> /dev/null; then
    echo -e "${RED}✗ rpmbuild не установлен${NC}"
    echo -e "${YELLOW}Для RedHat/CentOS установите: sudo yum install -y rpm-build${NC}"
    echo -e "${YELLOW}Для Fedora установите: sudo dnf install -y rpm-build${NC}"
    exit 1
fi

# Создание структуры RPM
echo -e "${YELLOW}Создание структуры RPM...${NC}"
mkdir -p rpm/SOURCES
mkdir -p rpm/SPECS
mkdir -p rpm/BUILD
mkdir -p rpm/RPMS
mkdir -p rpm/SRPMS

# Сборка rpm пакета
echo -e "${YELLOW}Сборка rpm пакета...${NC}"
rpmbuild -bb \
    --define "_topdir $(pwd)/rpm" \
    --define "_sourcedir $(pwd)" \
    --define "_builddir $(pwd)/rpm/BUILD" \
    rpm/SPECS/unit-converter.spec

# Поиск созданного RPM пакета
RPM_FILE=$(find rpm/RPMS -name "*.rpm" -type f 2>/dev/null | head -1)

# Проверка пакета
if [ -n "$RPM_FILE" ] && [ -f "$RPM_FILE" ]; then
    # Копируем RPM в корневую директорию
    cp "$RPM_FILE" .
    echo -e "${GREEN}✓ Пакет успешно создан: $(basename $RPM_FILE)${NC}"
    echo -e "${YELLOW}Информация о пакете:${NC}"
    rpm -qip "$RPM_FILE"
    echo ""
    echo -e "${YELLOW}Содержимое пакета:${NC}"
    rpm -qlip "$RPM_FILE"
else
    echo -e "${RED}✗ Ошибка при создании пакета${NC}"
    exit 1
fi
