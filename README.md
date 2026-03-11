<div align="center">

![Library](https://img.shields.io/badge/Library-brown?style=for-the-badge)
![C Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge)

*A foundational C utility library used across 42 projects*

</div>

<div align="center">
  <img src="/images/Libft.jpg">
</div>

# libft

[README en Español](README_es.md)

`libft` is a static C library that groups together reimplemented standard functions, linked-list utilities, formatted output helpers, and a few project-specific extensions. It is designed to serve as a base toolkit for 42 projects and general-purpose C development.

## 🔧 Installation

```bash
git clone https://github.com/Kobayashi82/Libft.git
cd Libft
make
```

The build generates a static library:

```bash
lib/libft.a
```

## 🖥️ Usage

### Build integration

Include the public headers and link against the generated archive:

```bash
cc example.c -Iinc lib/libft.a -o example
```

## 📄 License

This project is licensed under the WTFPL – [Do What the Fuck You Want to Public License](http://www.wtfpl.net/about/).

---

<div align="center">

**🧭 Developed as part of the 42 School curriculum 🧭**

*"Proof that reinventing the wheel is part of the curriculum"*

</div>
