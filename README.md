# MP3 Metadata Editor (ID3 Tag Reader & Editor)

## Author

Om Bidikar

---

## About the Project

This project is a command-line utility written in C to view and edit ID3 metadata tags in MP3 files.

It allows users to read, display, and modify important MP3 metadata such as title, artist, album, year, genre, and comments.

---

## 🎵 Features

* View all ID3 metadata tags from MP3 files
* Edit and update existing metadata fields
* Supports ID3v2 tag format
* Command-line based interface
* Lightweight and efficient implementation

---

## 📁 Project Structure

MP3_Tag_Reader/

Source Files:

* src/ (main.c, change.c, fedit.c, fvalidate.c)

Header Files:

* include/ (file.h)

Test Files:

* test_audio/ (sample.mp3)

Documentation:

* README.md

---

## ⚙️ How to Compile

```bash
gcc src/*.c -o mp3tag
```

---

## ▶️ How to Run

### View Tags

```bash
./mp3tag -v test_audio/sample.mp3
```

### Edit Tags

```bash
./mp3tag -e test_audio/sample.mp3
```

---

## 🧪 Supported Tags

The program supports reading and editing the following ID3 tags:

* Title (TIT2)
* Artist (TPE1)
* Album (TALB)
* Year (TYER)
* Genre (TCON)
* Comment (COMM)

---

## 🧠 Concepts Used

* File Handling (Binary Files)
* Structures and Pointers
* ID3 Tag Parsing
* String Manipulation
* Modular Programming in C

---

## ⚠️ Limitations

* Supports only ID3v2 format
* Limited error handling for corrupted MP3 files
* Command-line interface only

---

## 💡 How It Works

The program reads ID3 metadata frames from MP3 files and extracts relevant fields.
For editing, it modifies the corresponding frames and writes updated data back to the file.

---

## 📘 License

This project is for learning purposes.
