# ESP32 PSRAM std::vector Allocator  

## 🚀 Overview  
This repository provides a **custom allocator** to enable `std::vector` to use **PSRAM** (Pseudo Static RAM) on ESP32. By default, C++ STL containers allocate memory in DRAM, which is limited. With this allocator, large dynamic structures can efficiently reside in PSRAM.  

## 🎯 Why Use PSRAM?  
- **Ideal for large data structures** exceeding internal RAM.  
- **Avoids heap fragmentation** by managing memory efficiently.  
- **Supports large buffers** for graphics, sensor data, AI models, and more.  

## ⚠️ Limitations  
- Not all STL containers are well-suited for PSRAM.  
- Works best with contiguous memory allocations like `std::vector`.  
- Node-based structures (`std::map`, `std::unordered_map`) may not perform optimally due to PSRAM’s large allocation preference.  

## 🔧 Setup & Usage  

### 🛠️ Prerequisites  
- **ESP32** with **PSRAM support** enabled in the board configuration.  
- **Arduino framework** (ESP-IDF users can adapt accordingly). 
