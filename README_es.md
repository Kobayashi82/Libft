<div align="center">

![Library](https://img.shields.io/badge/Library-brown?style=for-the-badge)
![C Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge)

*Una biblioteca de utilidades fundamentales en C utilizada en proyectos de 42*

</div>

<div align="center">
  <img src="/images/Libft.jpg">
</div>

# libft

[README in English](README.md)

`libft` es una librería estática en C que reúne funciones reimplementadas de la librería estándar, utilidades para listas enlazadas, helpers de salida formateada y varias extensiones propias del proyecto. Está pensada como una base reutilizable para proyectos de 42 y para desarrollo general en C.

## 🔧 Instalación

```bash
git clone https://github.com/Kobayashi82/Libft.git
cd Libft
make
```

La compilación genera una librería estática:

```bash
lib/libft.a
```

## 🖥️ Uso

### Integración en compilación

Incluye los headers públicos y enlaza contra la librería generada:

```bash
cc example.c -Iinc lib/libft.a -o example
```

## 📄 Licencia

Este proyecto está licenciado bajo la WTFPL – [Do What the Fuck You Want to Public License](http://www.wtfpl.net/about/).

---

<div align="center">

**🧭 Desarrollado como parte del curriculum de 42 School 🧭**

*"Proof that reinventing the wheel is part of the curriculum"*

</div>
