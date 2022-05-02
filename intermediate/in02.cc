template<typename Type> class Singleton{
protected:
    Singleton() = default;
private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    template<typename... Args>
    static Type& getInstance(Args&&... args) {
        static Type instance(args...);
        return instance;
    }
};
class Mouse : public Singleton<Mouse> {
public:
    Mouse() {}
};
class Cursor : public Singleton<Cursor> {
public:
    Cursor(int x, int y) {}
};

int main() {
    Mouse& m = Mouse::getInstance();
    Cursor& c = Cursor::getInstance(1, 2);
}