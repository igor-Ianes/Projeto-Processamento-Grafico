# Projeto-Processamento-Grafico

<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->


<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
</div>

<div align="center">
  <div style="display: flex; justify-content: center; align-items: center; gap: 40px;">
    <img src="Images/OpenglLogo.png" style="height: 80px; object-fit: contain;">
    <img src="Images/GLFWlogo.png" style="height: 80px; object-fit: contain;">
  </div>

</div>

</div>




<!-- TABLE OF CONTENTS -->
  <details>
  <summary><strong>Índice</strong></summary>
  <ol>
    <li>
      <a href="#sobre-o-projeto">Sobre o Projeto</a>
      <ul>
        <li><a href="#construção">Construção</a></li>
        <li><a href="#objetivos">Objetivos</a></li>
      </ul>
    </li>
    <li>
      <a href="#pré-requisitos">Pré-requisitos</a>
    </li>
    <li>
      <a href="#execução">Execução</a>
    </li>
    <li>
      <a href="#uso">Uso</a>
    </li>
    <li>
      <a href="#controles">Controles</a>
    </li>
    <li>
      <a href="#features">Features</a>
    </li>
    <li>
      <a href="#desenvolvedor">Desenvolvedor</a>
    </li>
    <li>
      <a href="#license">Licença</a>
    </li>
    <li>
      <a href="#contact">Contato</a>
    </li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## Sobre o projeto

Este projeto foi desenvolvido com o objetivo de aplicar os conceitos estudados na disciplina de Processamento Gráfico, através da criação e visualização de uma cena 3D interativa.
O projeto foi realizado utilizando o GitHub para documentação das alterações realizadas.



## Construção

Essa seção lista as principais ferramentas utilizadas no desenvolvimento do projeto.

* ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
* ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* ![Vscode](https://img.shields.io/badge/Vscode-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)
* [![Git][Git.com]][Git-url]
* [![Linux][Linux.com]][Linux-url]


## Objetivos

Desenvolver uma cena 3D funcional implementando conceitos fundamentais de computação gráfica, incluindo:

* Renderização de objetos 3D
* Uso de shaders
* Manipulação de câmera
* Aplicação de texturas
* Animação básica
* Redimencionamento



## Pré requesitos

O ambiente é bem simples,
 Primeiro, você precisa de um compilador de C/C++ na sua maquina para a compilação do projeto, sendo recomendado o GCC. Se voce nao tem certeza se ja tem o compilador instalado pode executar o seguinte comando.
* GCC
  ```sh
  gcc –version
  ```

Em seguida, é necessario baixar a bibliioteca GLFW, e apos a extracao do arquivo, copiar a pasta GLFW para o repositorio Projeto.
* LINK
  ```sh
  https://www.glfw.org/download
  ```

### Execução

Aqui o passo a passo de como executar o projeto.

1. Clone o repositorio
   ```sh
   git clone https://github.com/igor-Ianes/Projeto-Processamento-Grafico
   ```
2. Copie a pasta GLFW no repositorio projeto e abra o projeto na sua IDE favorita
   ```js
   cd projeto
   ```
3. A estrutura final do projeto deve ser esta.
   ```js
    Projeto/
    ├── Assets/
    │   ├── TextureDragon.png
    │   ├── AsaEsquerda.obj
    │   ├── AsaDireita.obj
    │   ├── MontanhaNeve.obj
    │   └── Grama.jpg
    │   
    ├── GLFW/ 
    │   └── ...
    │   
    ├── Graficos3d/
    │   ├── Headers/
    │   │   ├── Framework/
    │   │   │   ├── Graphics.hpp
    │   │   │   ├── InputManager.hpp
    │   │   │   ├── Manager.hpp
    │   │   │   ├── MathHelper.hpp
    │   │   │   ├── stb_Image.hpp
    │   │   │   ├── TextureManager.hpp
    │   │   │   └── Timer.hpp
    │   │   │ 
    │   │   └── Engine/
    │   │       ├── Camera.hpp
    │   │       ├── Graphics3d.hpp
    │   │       ├── Math3d.hpp
    │   │       ├── Mesh.hpp
    │   │       ├── Object3D.hpp
    │   │       ├── OpenGL.hpp
    │   │       ├── Renderer3D.hpp
    │   │       ├── Scene.hpp
    │   │       └── Shader.hpp
    │   │
    │   └── Source/
    │       ├── Engine/
    │       │   ├── Graphics3d.cpp
    │       │   ├── Math3d.cpp
    │       │   ├── Renderer3D.cpp
    │       │   ├── Scene.cpp
    │       │   └── Shader.cpp
    │       └── Framework/
    │       │   ├── Graphics.cpp
    │       │   ├── InputManager.cpp
    │       │   ├── Manager.cpp
    │       │   ├── TextureManager.cpp
    │       │   └── Timer.cpp
    │       └── main.cpp
    └── MAKEFILE
   ```

4. execute o  `MAKEFILE` com o seguinte comando.
   ```js
   MAKE all
   ```





<!-- USAGE EXAMPLES -->
## Uso

Seguem alguns gifs da engine em execução.

### TEAPOT
<p float="left">
  <p align="middle">
  <img src="Images/teapot.gif" width="45%" hspace="20"/>
</p>

### CUBO
<p float="left">
  <p align="middle">
  <img src="Images/cubo.gif" width="45%" hspace="20"/>
</p>

### DRAGÕES
<p float="left">
  <p align="middle">
  <img src="Images/dragoes.gif" width="45%" hspace="20"/>
</p>


## Controles

A seguir seguem todos os controles da engine.

* W, A, D, S, F, G - Movimentação da camera.
* ↑ ↓ ← → - movimentação do objeto selecionado.
* M, N, B, V - movimentação do objeto selecionado no proprio eixo.
* 1, 2, 3, 4, -, + Redimensionamento do objeto selecionado.
* TAB seleciona proximo objeto em loop.
* Mouse - Movimenta camera e da zoom.


## Features:
o projeto teve como features implementadas:

* Renderização de objetos 3D a partir de um parser de .OBJ
* Iluminação basica
* movimentação dos objetos em todas as direções
* Possibilidade de alternar entre os objetos
* Possibilidade de se movimentar pela cena atraves de 3 cameras
* Utilização de Shader proprio
* Possibilidade de redimensionar qualquer objeto
* Suporte a textura
* Suporte a rotação e orbita de objetos
* Suporte a hierarquia nos objetos



## Desenvolvedor:
* Nome: Igor Ianes
* RA: 795593






<!-- LICENSE -->
## License

Distribuição sob a licença MIT. Veja `LICENSE.txt` para maiores informações.





<!-- CONTACT -->
## Contact

[![Gmail Badge](https://img.shields.io/badge/-Gmail-006bed?style=flat-square&logo=Gmail&logoColor=white&link=mailto:SEU-EMAIL)](mailto:SEU-EMAIL)


Project Link: [https://github.com/igor-Ianes/Projeto-Processamento-Grafico](https://github.com/igor-Ianes/Projeto-Processamento-Grafico)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/igor-Ianes/Projeto-Processamento-Grafico.svg?style=for-the-badge
[contributors-url]: https://github.com/igor-Ianes/Projeto-Processamento-Grafico/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/igor-Ianes/Projeto-Processamento-Grafico.svg?style=for-the-badge
[forks-url]: https://github.com/igor-Ianes/Projeto-Processamento-Grafico/network/members
[stars-shield]: https://img.shields.io/github/stars/igor-Ianes/Projeto-Processamento-Grafico.svg?style=for-the-badge
[stars-url]: https://github.com/igor-Ianes/Projeto-Processamento-Grafico/stargazers
[issues-shield]: https://img.shields.io/github/issues/igor-Ianes/Projeto-Processamento-Grafico.svg?style=for-the-badge
[issues-url]: https://github.com/igor-Ianes/Projeto-Processamento-Grafico/issues
[license-shield]: https://img.shields.io/github/license/igor-Ianes/Projeto-Processamento-Grafico.svg?style=for-the-badge
[license-url]: https://github.com/igor-Ianes/Projeto-Processamento-Grafico/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/igor-c-i-a8522920a/
[Git.com]:https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=white
[Git-url]:https://Git.com
[Linux.com]:https://img.shields.io/badge/Linux-000?style=for-the-badge&logo=linux&logoColor=FCC624
[Linux-url]:https://linux.com
