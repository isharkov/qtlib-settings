# libqt-settings

This is Qt library for easy saving and restoring object fiellds to file. It is gives you a good way to make application sattings and user defined options

## Installation
 1. clone git repository to your project
 2. add library to pro file:
 <pre>
    DEPENDPATH +=  . ../../qtlib-settings/src
    INCLUDEPATH +=  . ../../qtlib-settings/src
    CONFIG(debug, debug|release) {
    LIBS+=  -L../../qtlib-settings/src/debug -lqtlib-settings
  }
  CONFIG(release, debug|release) {
      LIBS+=  -L../../qtlib-settings/src/release -lqtlib-settings
  }
  </pre>

  
## Usage
  Add new parent class QtLib::AbstractSettings for your class, then implements three methods:
    <pre>
    1. virtual const QString getName(void) const;
    2. virtual void setSettings(const QMap<QString, QVariant> map);
    3. virtual const QMap<QString, QVariant> getSettings(void) const;
    </pre>

  You can sets default values in class.

## Example
 See example in example folder.

## Requirements
 Qt5.9 or higher

