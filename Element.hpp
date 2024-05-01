//Tworzenie struktury która za pomoc¹ jednego pointera wskazuje na jednoczeœnie priorytet i wartoœæ elementu
template <typename T, typename P>
class Element {

public:

    T value;
    P priority;

    Element(){}
    Element(const T& val, const P& prio) : value(val), priority(prio) {}

};
