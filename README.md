# Mini GL Renderer

A **lightweight, modern OpenGL rendering framework** built in C++14 for rapid prototyping, graphics research, and interactive application development.  
Mini GL Renderer provides clean abstractions for shaders, buffers, and rendering pipelines, while integrating seamlessly with [GLFW](https://www.glfw.org/) for windowing and [Dear ImGui](https://github.com/ocornut/imgui) for real-time UI.  

Designed to be modular and extensible, it serves as a solid foundation for building rendering features, experimenting with graphics techniques, or powering small-scale 3D/2D applications.  

![Renderer Demo](media/demo.gif)

---

## ✨ Features

- **Modern OpenGL (3.3+) Core** rendering pipeline  
- **Shader system** with runtime loading, compilation, and uniform management (`Shader.cpp`, `shader.h`)  
- Abstractions for **VAO**, **VBO**, and **EBO** with a clean API for mesh management  
- Integrated **Camera system** supporting perspective/orthographic projection and free movement  
- **Dear ImGui integration** for real-time debugging, performance stats, and editor-like controls  
- **Lighting support** with sample Phong shading implementation (`light.vert`, `light.frag`)  
- **Texture support** via [stb_image](https://github.com/nothings/stb)  
- Toggle between **wireframe and fill rendering modes**  
- **Renderer class** for frame orchestration and mesh drawing  
- Easily extensible for new mesh types and rendering techniques  

---

## 🚀 Getting Started

### Prerequisites

- C++14 compatible compiler (tested with **Visual Studio 2022**)  
- [GLFW](https://www.glfw.org/) (headers included in `Libraries/include`)  
- [Dear ImGui](https://github.com/ocornut/imgui) (included in `imgui/`)  
- [stb_image](https://github.com/nothings/stb) (included in `stb/`)  
- OpenGL 3.3+ drivers  

### Building

1. Clone the repository:
    ```sh
    git clone https://github.com/ayanchavand/Mini-GL-Renderer.git
    ```
2. Open `Mini GL Renderer.sln` in **Visual Studio 2022**.  
3. Build the solution (`Ctrl+Shift+B`).  

### Running

Run the project (`F5` in Visual Studio) or launch the built binary from the output directory.  
The application window will display rotating cubes, wireframe/fill toggle, and ImGui debug/camera controls.  

---

## 📂 Project Structure

- `main.cpp` – Application entry point, main loop, rendering setup  
- `Shader.cpp`, `shader.h` – Shader management (load/compile/use GLSL)  
- `VBO.cpp`, `VBO.h` – Vertex Buffer Object abstraction  
- `VAO.cpp`, `VAO.h` – Vertex Array Object abstraction  
- `EBO.cpp`, `EBO.h` – Element Buffer Object abstraction  
- `Camera.cpp`, `Camera.h` – Camera system for view/projection handling  
- `EngineGUI.cpp`, `EngineGUI.h` – ImGui-powered debug & editor panels  
- `Renderer.cpp`, `Renderer.h` – Renderer class for frame orchestration and drawing  
- `default.vert`, `default.frag` – Example GLSL shaders  
- `light.vert`, `light.frag` – Example lighting shaders  
- `imgui/` – Dear ImGui sources  
- `Libraries/include/GLFW/` – GLFW headers  
- `stb/` – stb_image header for texture loading  

---

## 📜 License

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details.
