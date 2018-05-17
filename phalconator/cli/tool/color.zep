
/*
 +------------------------------------------------------------------------+
 | Phalconator Library                                                    |
 +------------------------------------------------------------------------+
 | Copyright (c) Toroia Team (https://toroia.fr)                          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.                                 |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to contact@toroia.fr so we can send you a copy immediately.            |
 +------------------------------------------------------------------------+
 | Author(s): Toroia team and contributors <contact@toroia.fr>            |
 +------------------------------------------------------------------------+
 */

namespace Phalconator\Cli\Tool;

use Phalconator\Cli\Exception;

/**
 * Phalconator\Cli\Tool\Color
 *
 * The class color cli lines
 *
 */
class Color
{

  const COLORIZE = "[%sm";

  const UNCOLORIZE = "[0m";

  protected static _style = [
    "reset": 0,
    "bold": 1,
    "dark": 2,
    "italic": 3,
    "underline": 4,
    "blink": 5,
    "reverse": 7,
    "concealed": 8
  ];

  protected static _color = [
    "black": 30,
    "red": 31,
    "green": 32,
    "yellow": 33,
    "blue": 34,
    "magenta": 35,
    "cyan": 36,
    "light_gray": 37,
    "dark_gray": 90,
    "light_red": 91,
    "light_green": 92,
    "light_yellow": 93,
    "light_blue": 94,
    "light_magenta": 95,
    "light_cyan": 96,
    "white": 97
  ];

  protected static _background = [
    "black": 40,
    "red": 41,
    "green": 42,
    "yellow": 43,
    "blue": 44,
    "magenta": 45,
    "cyan": 46,
    "light_gray": 47,
    "dark_gray": 100,
    "light_red": 101,
    "light_green": 102,
    "light_yellow": 103,
    "light_blue": 104,
    "light_magenta": 105,
    "light_cyan": 106,
    "white": 107
  ];

  /**
   * Lock the constructor
   */
  private function __construct() {}

  /**
   * Render the string coloring
   */
  public static function render(string d, c = null, b = null, s = null) -> string
  {
    var concat, color, render;

    if empty d {
      throw new Exception("Data is required");
    }

    if (c && typeof c != "string") {
      throw new Exception("Bad color type");
    }
    
    if (b && typeof b != "string") {
      throw new Exception("Bad background type");
    }

    if (s && typeof s != "string") {
      throw new Exception("Bad style type");
    }

    let d = self::clear(d);

    let concat = self::_concat(c, b, s);

    let color = sprintf(self::COLORIZE, concat);

    let render = chr(27) . color . d . chr(27) . self::UNCOLORIZE;

    return render;
  }

  /**
   * Clear string coloring
   */
  public static function clear(string d) -> string
  {
    return preg_replace("#\\x1b[[][^A-Za-z]*[A-Za-z]#", null, d);
  }

  /**
   * Concat color, background and style into string
   */
  protected static function _concat(c = null, b = null, s = null) -> string
  {
    var co, bg, st;
    array concat;

    let concat = [];

    if fetch co, self::_color[c] {
      let concat[] = co;
    }

    if fetch st, self::_style[s] {
      let concat[] = st;
    }
    
    if fetch bg, self::_background[b] {
      let concat[] = bg;
    }

    return concat->join(";");
  }
}