PEDestrians DirectionSync FIX
=============================

Что исправлено:
1. Actor теперь создаётся сразу с правильным углом маршрута, а не с 0.0.
2. При заметном повороте маршрута (>18 градусов) Actor аккуратно пересоздаётся
   с новым facing angle, потому что обычный SetActorFacingAngle у уже
   застримленного SA-MP Actor клиенту надёжно не синхронизируется.
3. Убраны бесполезные SetActorFacingAngle на каждом physics tick.
4. Physics tick изменён с 80 ms на 60 ms для более плавного движения.
5. dt ограничен 0.12 sec, чтобы лаг сервера не вызывал большие телепорты.
6. SetPedestrianSkin теперь сохраняет текущий угол и virtual world.

Как понять, что запущена исправленная версия:
в server_log появится строка:
[Pedestrians] DirectionSync FIX enabled: spawn-facing + turn restream + 60ms movement

Файл src/main.cpp уже исправлен.

Сборка под старый хостинг:
- build_glibc217.sh рассчитан на 32-bit Linux.
- .github/workflows/build-glibc217.yml собирает через manylinux2014_i686,
  то есть с базовой совместимостью GLIBC 2.17.

После сборки замени:
plugins/pedestrians.so

Остальные файлы оставь прежними:
scriptfiles/pedpaths.json
scriptfiles/zone_skins.json
pawno/include/pedestrians.inc
