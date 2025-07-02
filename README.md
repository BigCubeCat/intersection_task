# Точка пересечения отрезков

<details>
  <summary>Задача</summary>
Есть класс трёхмерного вектора:
```cpp
class Vector3D {
    double X;
    double Y;
    double Z;
};
```
и трёхмерного отрезка, заданного двумя Vector3D:
```
class Segment3D {
    Vector3D start;
    Vector3D end;
};
```

Требуется написать функцию `Intersect`, которая будет находить точку `Vector3D` пересечения двух
заданных на вход `Segment3D`. В классы `Vector3D` и `Segment3D` можно добавлять любые методы.

</details>

## Сборка

**С использованием тестов**

(необходим GTest)
```bash
cmake -DUSE_TESTS=ON -S . -B build
cmake --build build
# Запуск тестов через ctest
ctest --test-dir ./build --output-on-failure
# Альтернатива - запуск исполняемого файла
./build/test/vector_test
```

**Без использования тестов**

(собирается без зависимостей)

```bash
cmake -S . -B build
cmake --build build
```

## P.S. 

В задании не указано, что должен выдавать метод при отсутствии пересечения или при наложении отрезков.
При отсутствии возвращается `std::nullopt`.
При наложении - точка начала или точка конца переданного вектора.