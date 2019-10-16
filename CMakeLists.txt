cmake_minimum_required(VERSION 3.14)
project(MarathonTranningCodes)

set(CMAKE_CXX_STANDARD 17)

add_executable(MarathonTranningCodes main.cpp)
add_executable(MapaDoMeistre RuanContest/Grafos/MapaDoMeistre.cpp)
add_executable(Costa RuanContest/Grafos/Costa.cpp)
add_executable(BalancoDeParentesis RuanContest/EstruturadeDados/BalancoDeParentesis.cpp)
add_executable(EmBraille RuanContest/ADHOCeAlg.Gulosos/EmBraille.cpp)
add_executable(LuzesDeNatal randomTasks/LuzesDeNatal.cpp)