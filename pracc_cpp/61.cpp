/*CRTP*/
#include <iostream>
#include <ranges>

#include <vector>

struct base_vtable {
    private:
        virtual void impl() = 0;
    public:
        void foo() {
            impl();
        }
};

struct derived_vtable_1 : base_vtable {
    void impl() override {
        std::cout << "derived_vtable_1" << std::endl;
    }
};

struct derived_vtable_2 : base_vtable {
    void impl()  override {
        std::cout << "derived_vtable_2" << std::endl;
    }
};

template<typename T>
struct base_crtp {
    void foo() {
        static_cast<T&>(*this).impl();
    }
};

struct derived_crtp_1 : base_crtp<derived_crtp_1> {
    void impl() {
        std::cout << "derived_crtp_1" << std::endl;
    }
};

struct derived_crtp_2 : base_crtp<derived_crtp_2> {
    void impl() {
        std::cout << "derived_crtp_2" << std::endl;
    }
};

int main() {

    base_vtable&& ref_vtable_1 = derived_vtable_1{};
    base_vtable&& ref_vtable_2 = derived_vtable_2{};

    ref_vtable_1.foo();
    ref_vtable_2.foo();

    std::cout << "derived_vtable_1 sizeof: " << sizeof(derived_vtable_1) << std::endl;
    std::cout << "derived_vtable_2 sizeof: " << sizeof(derived_vtable_2) << std::endl;

    base_crtp ref_crtp_1 = derived_crtp_1{};
    base_crtp ref_crtp_2 = derived_crtp_2{};

    ref_crtp_1.foo();
    ref_crtp_2.foo();

    std::cout << "derived_crtp_1 sizeof: " << sizeof(derived_crtp_1) << std::endl;
    std::cout << "derived_crtp_2 sizeof: " << sizeof(derived_crtp_2) << std::endl;

    return 0;
}
