Name:           unit-converter
Version:        1.0.0
Release:        1%{?dist}
Summary:        Конвертер единиц измерения

License:        MIT
URL:            https://github.com/K4l1br1/converter

Requires:       libstdc++ >= 4.8

%description
Программа для конвертации различных единиц измерения:
- Расстояние (метры, километры, мили, футы и т.д.)
- Вес (килограммы, граммы, фунты, унции и т.д.)
- Температура (Цельсий, Фаренгейт, Кельвин)

%prep
# Подготовка исходников
cd %{_sourcedir}

%build
# Компиляция проекта
cd %{_sourcedir}
make -j$(nproc)

%install
# Установка бинарников
cd %{_sourcedir}
make install DESTDIR=%{buildroot} PREFIX=%{_prefix}

%clean
# Очистка временных файлов
rm -rf %{buildroot}

%files
%{_bindir}/unit_converter

%changelog
* Sat Dec 06 2025 K4l1br1 <k4l1br1@example.com> - 1.0.0-1
- Initial release
