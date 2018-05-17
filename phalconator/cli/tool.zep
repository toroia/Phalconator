
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

use Phalconator\Cli\Tool\Color;

/**
 * Phalcon\Cli\Tool
 *
 * <p>Phalcon\Cli\Tool is simply tool</p>
 */
class Tool
{

  protected _data;

  /**
   * Phalconator\Cli\Tool constructor
   */
  public function __construct(string d)
  {
    if empty d {
      throw new Exception("Data is required");
    }

    let this->_data = d;
  }

  public function __toString()
  {
    return this->_data . PHP_EOL;
  }

  public function clear()
  {
    let this->_data = Color::clear(this->_data);

    return this;
  }

  public function line()
  {
    let this->_data = this->_data . PHP_EOL;

    return this;
  }

  public function colorize(c = null, b = null, s = null) -> <Tool>
  {
    let this->_data = Color::render(this->_data, c, b, s);
    
    return this;
  }
}
