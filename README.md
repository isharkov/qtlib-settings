# libqt-settings

Qt library for easy saving and restoring object fiellds to file.

## Installation
 1. clone git repository to your project
 2. add library to pro file:
  DEPENDPATH +=  . ../../libqt-settings/src
  INCLUDEPATH +=  . ../../libqt-settings/src
  CONFIG(debug, debug|release) {
      LIBS+=  -L../../libqt-settings/src/debug -llibqt-settings
  }
  CONFIG(release, debug|release) {
      LIBS+=  -L../../libqt-settings/src/release -llibqt-settings
  } 

  
## Usage
  Add new parent class LibQt::AbstractSettings for your class, then implements three methods:
    1. virtual const QString getName(void) const;
    2. virtual void setSettings(const QMap<QString, QVariant> map);
    3. virtual const QMap<QString, QVariant> getSettings(void) const;

  You can sets default values in class.

## Example
 See example in example folder.

## Requirements
 Qt5.9 or higher

