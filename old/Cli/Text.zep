
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
