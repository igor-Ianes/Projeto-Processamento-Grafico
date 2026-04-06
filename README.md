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
  <summary>indice</summary>
  <ol>
    <li>
      <a href="#about-the-project">Sobre o projeto</a>
      <ul>
        <li><a href="#built-with">Construção</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Como usar</a>
      <ul>
        <li><a href="#prerequisites">Pré requesitos</a></li>
        <li><a href="#installation">instalação</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## Sobre o projeto

Este projeto foi desenvolvido com o objetivo de aplicar os conceitos estudados na disciplina de Processamento Gráfico, através da criação e visualização de uma cena 3D interativa.
O projeto foi realizado utilizando o GitHub para documentação das alterações realizadas.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Construção

Essa seção lista as principais ferramentas utilizadas no desenvolvimento do projeto.

* ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
* ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* ![Vscode](https://img.shields.io/badge/Vscode-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)
* [![Git][Git.com]][Git-url]
* [![Linux][Linux.com]][Linux-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Objetivos

Desenvolver uma cena 3D funcional implementando conceitos fundamentais de computação gráfica, incluindo:

* Renderização de objetos 3D
* Uso de shaders
* Manipulação de câmera
* Aplicação de texturas
* Animação básica
* Redimencionamento

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Pré requesitos

O ambiente é bem simples,
 Primeiro, você precisa de um compilador de C/C++ na sua maquina para a compilação do projeto, sendo recomendado o GCC. Se voce nao tem certeza se ja tem o compilador instalado pode executar o seguinte comando.
* GCC
  ```sh
  gcc –version
  ```

Em seguida, é necessario baixar a bibliioteca GLFW, e apos a extracao do arquivo, copiar a pasta GLFW para a raiz do projeto.
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
2. Copie a pasta GLFW para a raiz do projeto e abra o projeto na sua IDE favorita
   ```js
   cd projeto
   ```

3. execute o  `MAKEFILE` com o seguinte comando.
   ```js
   MAKE all
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



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

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Controles

A seguir seguem todos os controles da engine.

* W, A, D, S, F, G - Movimentação da camera.
* ↑ ↓ ← → - movimentação do objeto selecionado.
* M, N, B, V - movimentação do objeto selecionado no proprio eixo.
* 1, 2, 3, 4, -, + Redimensionamento do objeto selecionado.
* TAB seleciona proximo objeto em loop.
* Mouse - Movimenta camera e da zoom.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Features:
o projeto teve como features implementadas:

* Renderização de objetos 3D a partir de um parser de .OBJ
* Iluminação dinamica
* movimentação dos objetos em todas as direções
* Possibilidade de alternar entre os objetos
* Possibilidade de se movimentar pela cena atraves de 3 cameras
* Utilização de Shader proprio
* Possibilidade de redimensionar qualquer objeto
* Suporte a textura
* Suporte a rotação e orbita de objetos
* Suporte a hierarquia nos objetos

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Desenvolvedor:
* Nome: Igor Ianes
* RA: 795593


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distribuição sob a licença MIT. Veja `LICENSE.txt` para maiores informações.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



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
