# Mini GL Renderer

A lightweight OpenGL renderer project built with C++14, designed for educational purposes and rapid prototyping. The project demonstrates modern OpenGL techniques, including shader management, vertex buffer objects (VBO), vertex array objects (VAO), and integration with popular libraries such as GLFW and Dear ImGui.

## Features

- Modern OpenGL (3.3+) rendering pipeline
- Custom shader loading and compilation (`Shader.cpp`, `shader.h`)
- Vertex Buffer Object (VBO) and Vertex Array Object (VAO) abstraction
- Window and input management via [GLFW](https://www.glfw.org/)
- Immediate-mode GUI integration using [Dear ImGui](https://github.com/ocornut/imgui)
- Example vertex (`default.vert`) and fragment (`default.frag`) shaders
- Camera system with configurable position and projection
- Wireframe and fill rendering modes toggle
- Texture loading via stb_image
- Real-time debug and camera info windows using ImGui
- Clean, modular C++ codebase

## Getting Started

### Prerequisites

- Visual Studio 2022 (or compatible C++14 compiler)
- [GLFW](https://www.glfw.org/) (included in `Libraries/include`)
- [Dear ImGui](https://github.com/ocornut/imgui) (included in `imgui/`)
- [stb_image](https://github.com/nothings/stb) (included in `stb/`)
- OpenGL drivers supporting version 3.3 or higher

### Building

1. Clone the repository:
    ```sh
    git clone https://github.com/ayanchavand/Mini-GL-Renderer.git
    ```
2. Open `Mini GL Renderer.sln` in Visual Studio 2022.
3. Build the solution (`Ctrl+Shift+B`).

### Running

- Run the project from Visual Studio (`F5`) or execute the built binary from the output directory.
- The application window will display a textured quad, wireframe/fill toggle, and ImGui debug/camera windows.

## Project Structure

- `main.cpp` – Application entry point, window setup, main loop, rendering, camera, GUI
- `Shader.cpp`, `shader.h` – Shader class for loading, compiling, and using GLSL shaders
- `VBO.cpp`, `VBO.h` – Vertex Buffer Object abstraction
- `VAO.cpp`, `VAO.h` – Vertex Array Object abstraction
- `EBO.cpp`, `EBO.h` – Element Buffer Object abstraction
- `Camera.cpp`, `Camera.h` – Camera system for view/projection matrices
- `EngineGUI.cpp`, `EngineGUI.h` – ImGui-based debug and camera windows
- `default.vert`, `default.frag` – Example GLSL shader files
- `imgui/` – Dear ImGui source and configuration
- `Libraries/include/GLFW/` – GLFW headers
- `stb/` – stb_image for texture loading

## License

MIT License

