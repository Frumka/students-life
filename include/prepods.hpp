//
// Created by atrum on 07.12.19.
//

#ifndef STUDENT_LIFE_MAIN_PREPODS_HPP
#define STUDENT_LIFE_MAIN_PREPODS_HPP

#include <map>
#include <string>

/** Класс - плейсхолдер для преподавателей
 *  Единственная причина его существования - необходимость map-a acessor для парсинга ивентов
 *  Для подключентя к обработчику ивентов:
 *
    prepod A, K;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"A", A.acessor},
            {"K", K.acessor},
    };
 *
 */
class prepod{
public:
    std::string name;
    std::string mark = "2";
    std::map<std::string, std::string*> acessor = {
            {"mark", &mark},
            {"name", &name}
    };
    prepod(std::string _name, std::string _mark){
        name = _name;
        mark = _mark;
    }
/* Is used for tests in ../event_processor/tests
    std::string checkit(){
        return mark;
    }
    */
};

#endif //STUDENT_LIFE_MAIN_PREPODS_HPP
