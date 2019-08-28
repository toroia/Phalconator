
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc;

use Phalcon\Di\Injectable;
use Phalcon\Domain\Payload\PayloadFactory;
use Phalcon\Domain\Payload\PayloadInterface;
use Phalcon\Mvc\ControllerInterface;

abstract class ResourceController extends Injectable implements ControllerInterface
{
    /** @var \Phalcon\Domain\Payload\PayloadFactory payload */
    protected payload;

    /**
     * Phalconator\Mvc\ResourceController constructor
     */
    final public function __construct()
    {
        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }

        if typeof this->payload != "object" {
            let this->payload = new PayloadFactory;
        }
    }

    final public function afterExecuteRoute(<Dispatcher> dispatcher)
    {
        var content;

        let content = $dispatcher->getReturnedValue();

        switch (typeof content) {
            case "object":
                this->response->setJsonContent(content->getOutput());
                break;

            default:
                return this->response->setJsonContent([]);
                break;
        }
    }
}
