//###########################################################################################
// RF3Sens (RoboForum triangulation range sensor)
// http://roboforum.ru/forum107/topic15929.html (official language for this forum - russian)
// MIT License
// 2015-2016
// Дмитрий Лилик (aka Dmitry__ @ RoboForum.ru)
// Андрей Пожогин (aka dccharacter  @ RoboForum.ru)
// Сергей Тараненко (aka setar @ RoboForum.ru)
//###########################################################################################

Высокоточный (0.01+ mm) оптический барьерный датчик расстояния до поверхности стола 3D принтеров.
Основан на анализе картины засветки пзс матрицы (от мыши) рассеяным излучением от лазерного источника,
по принципу треугольника, при заранее известных углах установки лазера и матрицы.
Не зависит от типа материала стола (теоретически, методика пока в разработке).

Заявленная точность уже получена практическим путем на прототипах.

vvv======== печатная каретка 3D принтера ==============vvv
     -- лазер ------- сенсор --(печатная плата сенсора)
         \\\\       ||||
            \         |
             \        |
              \       |
               \      |
                \     |
                 \    |
                  \   |
                   \  |
                    \ |
                     \|
------ уровень -------*--- срабатывания -------------------
                      |\
                      | \
    тут датчик не видит пятна лазера и нет срабатывания
^^^=============== стол 3D принтера ====================^^^



* Схемы подключения разных ардуин (и других микроконтроллеров) в папке doc