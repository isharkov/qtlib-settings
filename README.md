# libqt-settings

Qt module for saving and restoring object fiellds to file.

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
	Add inherit your class from AbstractSettings, then implements three methods:
	    virtual const QString getName(void) const;
		virtual void setSettings(const QMap<QString, QVariant> map);
		virtual const QMap<QString, QVariant> getSettings(void) const;

	You can sets default values in class

## Example
 See example in example folder.

