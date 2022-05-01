template<typename Type, typename ...Args> class Singleton{
protected:
    Singleton(Args...args) {}
private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Type& getInstance(int x, int y) {
        static Type instance(x, y);
        return instance;
    }
};
class Cursor : public Singleton<Cursor> {
public:
    Cursor(int x, int y): Singleton(x, y) {}
};

int main() {
    Cursor& c = Cursor::getInstance(1, 2);
    //Mouse& c = Mouse::getInstance();
}

// class Mouse : public Singleton<Mouse> {
// public:
//     Mouse() {}
// };
