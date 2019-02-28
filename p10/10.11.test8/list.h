#ifndef LIST_H_
#define LIST_H_


struct point{
    double x;
    double y;
};

typedef point Item;

// namespace mylist{
    class List{
        private:
            // static const int LEN = 5;
            unsigned int mSize;
            Item * items;
            int current_pt;
        public:
            List(unsigned int size = 0);
            ~List();
            void add(Item & item);
            void remove();
            bool isempty() const;
            bool isfull() const;
    };

// }
#endif