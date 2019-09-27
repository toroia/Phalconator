
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Session\Adapter;

use SessionHandlerInterface;

/**
 * Class Jwt
 *
 * @package Phalconator\Session\Adapter
 * @doc https://github.com/byjg/jwt-session/blob/master/src/JwtSession.php
 */
class Jwt implements SessionHandlerInterface
{
  public function close() -> bool
  {
    return true;
  }

  public function destroy(var id) -> bool
  {
    return true;
  }

  public function gc(var maxlifetime) -> bool
  {
    return true;
  }

  public function read(var id) -> string
  {
    return "";
  }

  public function open(var savePath, var sessionName) -> bool
  {
    return true;
  }

  public function write(var id, var data) -> bool
  {
    return true;
  }
}
