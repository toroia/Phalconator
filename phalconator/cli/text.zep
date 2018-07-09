
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

namespace Phalconator\Cli;

use Phalconator\Cli\Text\Color;

/**
 * Phalcon\Cli\Text
 *
 * <p>Phalcon\Cli\Text is simply text</p>
 */
class Text
{

  protected _data;

  /**
   * Phalconator\Cli\Text constructor
   */
  public function __construct(string data)
  {
    if empty data {
      throw new Exception("Data is required");
    }

    let this->_data = data;
  }

  public function __toString()
  {
    return this->_data . PHP_EOL;
  }

  public function clear() -> <Tool>
  {
    let this->_data = Color::clear(this->_data);

    return this;
  }

  public function line() -> <Tool>
  {
    let this->_data = this->_data . PHP_EOL;

    return this;
  }

  public function colorize(color = null, background = null, style = null) -> <Tool>
  {
    let this->_data = Color::render(this->_data, color, background, style);

    return this;
  }
}
