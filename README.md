# Qt Notepad Tutorial - Devlog and README

This document serves as both a development log and a preliminary README for a simple Notepad application built using Qt, following the official Qt documentation tutorial. It chronicles the learning process, challenges faced, and solutions found while building the application.

## Project Overview

The goal of this project was to create a basic text editor similar to Notepad, leveraging Qt's framework for GUI development, cross-platform compatibility, and its signals/slots mechanism. The project was built incrementally, with each step focusing on a specific feature or Qt concept.

## Development Log

### Phase 1: Project Setup and Basic UI

**CMake Fundamentals:** The project started with understanding the basics of CMake, a cross-platform build system generator. Key concepts covered included:

- `CMakeLists.txt`: The file that describes the project structure and dependencies.
- `cmake_minimum_required`, `project`, `add_executable`, `target_link_libraries`: Essential CMake commands.

**Qt File Structure (.ui, .h, .cpp):** Learned the roles of the core Qt file types:

- `.ui`: Files created by Qt Designer, defining the user interface visually.
- `.h`: Header files, declaring classes and their members (including slots).
- `.cpp`: Source files, implementing the application logic.
- `uic`: The User Interface Compiler, which converts `.ui` files into C++ code (e.g., `ui_notepad.h`).

**Notepad Class Structure:** Designed the `Notepad` class:

- Included a pointer to the UI object (`Ui::Notepad`).
- Used `setupUi(this)` to initialize the UI from the `.ui` file.
- Defined slots to handle user actions.
- Understood the use of forward declarations to avoid circular dependencies.

**Signals and Slots Introduction:** Grasped Qt's core mechanism for inter-object communication:

- Signals are emitted by objects when something happens (e.g., a button click).
- Slots are functions that are called in response to signals.
- `connect()`: The function used to establish connections between signals and slots.
- Qt's signals and slots provide type safety and loose coupling, embodying the Observer pattern.

**Qt Designer - Action Editor and Toolbars:**

- Used Action Editor to create QAction objects for menus.
- Adding those actions into the toolbar.
- Qt Designer _automatically_ connects the `triggered()` signal of a `QAction` to a corresponding slot when the action is added to a toolbar if following `on_objectName_signalName()` convention.

### Phase 2: Implementing Core Functionality

**File Operations (Open, New, Save, Save As):** Implemented the basic file operations:

- Used `QFileDialog` to get file paths from the user.
- Used `QFile` and `QTextStream` for reading and writing file contents.
- Handled potential file errors (e.g., file not found).

**Printing:** Added print functionality using `QPrinter` and `QPrintDialog`, making the application much easier to print documents.

**Application Exit:** Implemented a clean exit mechanism:

- Used `QCoreApplication::quit()` (or `qApp->quit()`) to terminate the application gracefully. This ensures proper cleanup and signal emission.

**Adding Tooltips:** Added tooltips for the actions that are in the menus.

### Phase 3: Preferences and UI Refinements

**Font Selection:**

- Used `QFontDialog` to allow the user to choose a font.
- Applied the selected font to the `QTextEdit`.
- Fixed an issue where the initially selected font wasn't highlighted in the dialog.

**Persistent Settings (QSettings):** Used `QSettings` to store and retrieve user preferences:

- Saved the selected font.
- Saved and restored the main window's geometry (size and position).
- Used `QCoreApplication::setOrganizationName()` and `QCoreApplication::setApplicationName()` to ensure consistent settings storage.
- Initially, there's a problem on persisting the font preference because of incorrect `fromString` implementation.

**Application Icon:**

- Set the application icon using `setWindowIcon(QIcon(":/path/to/icon.png"))`.
- Implemented the **Qt Resource System (.qrc):**
  - Created a `resources/` folder to store assets (icons, images, etc.).
  - Organized resources into subfolders (e.g., `resources/icons/`).
  - Created a `.qrc` file to list the resources.
  - Referenced resources in code using the `:/prefix/resource.png` syntax. This embeds the resources within the application binary for better portability.

**UI Styling (QSS):**
Used Qt Style Sheets (QSS) to customize the appearance of the application:

- Removed the purple focus indicator outline from the `QTextEdit`.

**Window Management:**

- Used `setMinimumSize()` to prevent the window from being resized too small.

- Saved and restored window size using `QSettings`, overriding `closeEvent` of `QMainWindow`.

**Minimum and Maximum size of widgets:** Used Qt Designer to set the min/max size of the widgets.

**About Dialog:**

- Implemented using `QDialog`.
- Connected a close button to close the dialog.
- Learned how to pass parent widget in creating dialog instances.

**Layout Management:** Explored saving and loading window sizes, adjusting layout behavior (like making layouts "hug" contents), and working with layout constraints.

**Debugging Output:**

- `qDebug()` - main way to display debugging messages.

### Phase 4: Release and Distribution

**Creating Release Version:**

- Used `windeployqt` to package all libraries for distribution.
- Checked Qt installation path and adding it to system's PATH.

## Future Improvements

- **Status bar:** Shows the cursor position like which column and character count.
- **Save app's window position:** Save the current position of the application's window on close and reload on open.
- **Keyboard shortcuts:** Allow shortcuts like `Ctrl` + `S` to save and so on.

## Conclusion

This project provided a valuable hands-on introduction to Qt development. It covered a wide range of topics, from basic UI design to application logic, persistent settings, and deployment. The iterative development process, documented in this devlog, highlights the learning curve and the importance of continuous refinement in software development.
