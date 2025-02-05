#include <vector>
#include "esp32-hal-psram.h"

template<class T>
struct PSallocator {
    using value_type = T;

    PSallocator() = default;
    template<class U> constexpr PSallocator(const PSallocator<U>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t n) {
        if (n > std::size_t(-1) / sizeof(T)) {
            log_e("Allocation size too large!");
            return nullptr; 
        }

        T* p = static_cast<T*>(ps_malloc(n * sizeof(T)));
        if (!p) {
            log_e("PSRAM allocation failed!");
        }
        return p;
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::free(p);
    }
};

void setup() {
    Serial.begin(115200);

    if (!psramFound()) {
        log_e("PSRAM not found. Ensure your ESP32 model supports it.");
        return;
    }
    log_i("PSRAM detected. Allocating vector...");

    std::vector<int, PSallocator<int>> v;
    v.reserve(900000); // Allocates in PSRAM
    log_i("Vector capacity in PSRAM: %d", v.capacity());

    v.clear();           // Clears the vector
    v.shrink_to_fit();   // Releases unused memory
    log_i("Vector successfully managed in PSRAM.");
}

void loop() {}
