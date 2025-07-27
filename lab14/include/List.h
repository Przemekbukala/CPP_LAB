/**
 * @class Node
 * @brief Klasa bazowa reprezentująca węzeł listy.
 * 
 * Zapewnia podstawową funkcjonalność listy jednokierunkowej:
 * przechowuje wskaźnik na następny węzeł, umożliwia dynamiczne sprawdzanie typu za pomocą RTTI.
 */

class Node{
    public:
        /**
     * @brief Wirtualny destruktor - rekurencyjnie usuwa kolejne węzły listy.
     */
    virtual ~Node(){
        delete m_next;
    }
        /**
     * @brief Zwraca wskaźnik na następny węzeł.
     * @return Wskaźnik do następnego węzła lub nullptr, jeśli brak następnego.
     */
    Node *next()const{
        return m_next;
    }
    Node():m_next(nullptr){}
    Node(Node* m_next):m_next(m_next){}

    /**
     * @brief Szablonowa metoda sprawdzająca, czy węzeł przechowuje wartość typu T.
     * 
     * @tparam T Typ, który chcemy sprawdzić.
     * @return true jeśli typ węzła to T, false w przeciwnym wypadku.
     */
    template<typename T> bool isType() const;
    /**
     * @brief Czysto wirtualna metoda do dynamicznego sprawdzania typu (RTTI).
     * 
     * Porównuje przekazany typ z typem przechowywanej wartości.
     * 
     * @param type Informacja o typie do porównania.
     * @return true jeśli typ jest zgodny, false w przeciwnym wypadku.
     */
   virtual bool isTypeRTTI(const std::type_info&)const=0; 
   protected:
   Node* m_next;
};



 template<typename T> bool Node::isType() const{
      return  isTypeRTTI(typeid(T));
   }
/**
 * @class TNode
 * @brief Szablonowa klasa reprezentująca konkretny węzeł listy przechowujący wartość typu T.
 * Dziedziczy po Node, implementuje metody do sprawdzania typu i pobierania wartości.
 * @tparam T Typ przechowywanej wartości.
 */

template <typename T> class TNode: public Node {
    public:
     /**
     * @brief Konstruktor inicjujący węzeł z wartością i opcjonalnym następnym węzłem.
     * @param value Wartość przechowywana w węźle.
     * @param next_node Wskaźnik na następny węzeł (domyślnie nullptr).
     */
    TNode(T value,Node* next_node);
      /**
     * @brief Konstruktor inicjujący węzeł tylko z wartością.
     * @param value Wartość przechowywana w węźle.
     */
     TNode(T value);
    bool isTypeRTTI(const std::type_info& type)const;

    /**
     * @brief Zwraca przechowywaną wartość.
     * @return Stała referencja do wartości.
     */
    const T & get()const;
    private:
    T data;
};

template <typename T>  bool TNode<T>::isTypeRTTI(const std::type_info& type)const{
        return typeid(T)==type;
    }  
template <typename T>  const T & TNode<T>::get()const{
        return data;
    };
template <typename T>   TNode<T>::TNode(T value):data(value),Node(){
    }
template <typename T> TNode<T>::TNode(T value,Node* next_node):data(value),Node(next_node){
    } 
/**
 * @class List
 * @brief Lista jednokierunkowa przechowująca elementy różnych typów.
 * 
 * Umożliwia dodawanie elementów oraz pobieranie wartości poprzez dynamiczne sprawdzanie typu.
 */
class List{
    public:
        /**
     * @brief Konstruktor inicjujący pustą listę.
     */
    List():m_head(nullptr){}
    Node * head()const{
        return m_head;
    }
    /**
     * @brief Dodaje nowy element typu T na początek listy.
     * 
     * @tparam T Typ dodawanego elementu.
     * @param v Wartość do dodania.
     */
    template<typename T>
    void add(T v);
    template<typename T>
    static const T& get(const Node* obj);

    /**
     * @brief Destruktor usuwający wszystkie węzły listy.
     */
   ~List(){
    delete m_head;
   }
    private:
    Node *m_head;
};

 template<typename T>
    void List::add(T v){
    TNode<T>* ptr =new TNode<T>(v, m_head);
        m_head=ptr;
    };


    template<typename T>
  const T& List::get(const Node* obj){
        if(obj->isType<T>()){
           return  static_cast<const TNode<T>*>(obj)->get();
        }
   }
   


