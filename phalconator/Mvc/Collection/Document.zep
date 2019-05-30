
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc\Collection;

use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Collection\Exception;

/**
 * Phalconator\Mvc\Collection\Document
 *
 * This component allows Phalconator\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Document implements DocumentInterface, EntityInterface, \ArrayAccess
{
	/**
	 * Phalconator\Mvc\Collection\Document constructor
	 */
	public final function __construct()
	{
		if method_exists(this, "onConstruct") {
			this->{"onConstruct"}();
		}
	}

	/**
	 * Returns a cloned document
	 */
	public static function cloneResult(array! data) -> <DocumentInterface>
	{
		var source, document, key, value;

		let source = get_called_class();
		let document = new {source};

		for key, value in data {
			document->writeAttribute(key, value);
		}

		return document;
	}

	/**
	 * Checks whether an offset exists in the document
	 *
	 * @param int index
	 * @return boolean
	 */
	public function offsetExists(var index) -> boolean
	{
		return isset this->{index};
	}

	/**
	 * Returns the value of a field using the ArrayAccess interfase
	 */
	public function offsetGet(var index)
	{
		var value;
		if fetch value, this->{index} {
			return value;
		}
		throw new Exception("The index does not exist in the row");
	}

	/**
	 * Change a value using the ArrayAccess interface
	 */
	public function offsetSet(var index, value) -> void
	{
		let this->{index} = value;
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param string offset
	 */
	public function offsetUnset(offset)
	{
		throw new Exception("The index does not exist in the row");
	}

	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 *  echo $robot->readAttribute("name");
	 *</code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(attribute)
	{
		var value;
		if fetch value, this->{attribute} {
			return value;
		}
		return null;
	}

	/**
	 * Writes an attribute value by its name
	 *
	 *<code>
	 *  $robot->writeAttribute("name", "Rosey");
	 *</code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value) -> void
	{
		let this->{attribute} = value;
	}

	/**
	 * Returns the instance as an array representation
	 *
	 * @return array
	 */
	public function toArray()
	{
		return get_object_vars(this);
	}
}
