//Tworzenie struktury kt�ra za pomoc� jednego pointera wskazuje na jednocze�nie priorytet i warto�� elementu
template <typename T, typename P>
class Element {

public:

    T value;
    P priority;

    Element(){}
    Element(const T& val, const P& prio) : value(val), priority(prio) {}

};
