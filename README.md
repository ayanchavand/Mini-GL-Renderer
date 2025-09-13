# Mini GL Renderer

A lightweight OpenGL renderer project built with C++14, designed for educational purposes and rapid prototyping. The project demonstrates modern OpenGL techniques, including shader management, vertex buffer objects (VBO), vertex array objects (VAO), and integration with popular libraries such as GLFW and Dear ImGui.

## Features

- **Modern OpenGL (3.3+)** rendering pipeline
- Custom shader loading and compilation (`Shader.cpp`, `shader.h`)
- Vertex Buffer Object (VBO) and Vertex Array Object (VAO) abstraction
- Window and input management via [GLFW](https://www.glfw.org/)
- Immediate-mode GUI integration using [Dear ImGui](https://github.com/ocornut/imgui)
- Example vertex (`default.vert`) and fragment (`default.frag`) shaders
- Clean, modular C++ codebase

## Getting Started

### Prerequisites

- Visual Studio 2022 (or compatible C++14 compiler)
- [GLFW](https://www.glfw.org/) (included in `Libraries/include`)
- [Dear ImGui](https://github.com/ocornut/imgui`) (included in `imgui/`)
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
- The application window will display a simple rendered scene and an ImGui interface.

## Project Structure

- `main.cpp` — Application entry point, window setup, main loop
- `Shader.cpp`, `shader.h` — Shader class for loading, compiling, and using GLSL shaders
- `VBO.cpp`, `VBO.h` — Vertex Buffer Object abstraction
- `VAO.cpp`, `VAO.h` — Vertex Array Object abstraction
- `default.vert`, `default.frag` — Example GLSL shader files
- `imgui/` — Dear ImGui source and configuration
- `Libraries/include/GLFW/` — GLFW headers

