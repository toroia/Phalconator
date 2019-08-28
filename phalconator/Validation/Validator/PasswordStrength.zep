
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\AbstractValidator;

/**
 * Phalconator\Validation\Validator\Password
 *
 * Checks if the provided password is strong enough
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalconator\Validation\Validator\Password as PasswordValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new PasswordValidator(
 *         [
 *             "message" => "The password is not strong enought",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "anotherPassword",
 *     ],
 *     new PasswordValidator(
 *         [
 *             "message" => [
 *                 "password"        => "The password is not strong enought",
 *                 "anotherPassword" => "The another password is not strong enought",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class PasswordStrength extends AbstractValidator
{
	const MIN_VALID_SCORE = 2;

	protected template = "Field :field does not have a high enough score";

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var password, allowEmpty, minScore, passwordScore;

		let password = validation->getValue(field),
			allowEmpty = this->getOption("allowEmpty");

		// Checks if the password can be empty, then checks if the password is scalar and empty, or null
		if allowEmpty & ((is_scalar(password) & password === "") | password === null) {
			return true;
		}

		let minScore = (this->hasOption("minScore") ? this->getOption("minScore") : self::MIN_VALID_SCORE);

		// Gets the password score (high score = strong password)
		let passwordScore = this->scoreCalculator(password);

		// Checks if the password is a string
		// Checks that the password score is greater than or equal to the minimum score
		if is_string(password) & passwordScore >= minScore {
			return true;
		}

		validation->appendMessage(
            this->messageFactory(validation, field)
        );

		return false;
	}

	/**
	 * Function used to calculate the score of a provided password
	 * The higher the score, the stronger the password and vice versa
	 * @param  string password
	 * @return int
	 */
	private function scoreCalculator(password) -> int
	{
		var score, hasLower, hasUpper, hasNumber, passwordLength;

		let score = 0,
			hasLower = preg_match("![a-z]!", password),
			hasUpper = preg_match("![A-Z]!", password),
			hasNumber = preg_match("![0-9]!", password);

		// Increases the score if the password contains upper and lower case letters
		if hasLower & hasUpper {
			let score++;
		}

		// Increases the score if the password contains numbers and upper or lower case letters
		if (hasNumber & hasLower) | (hasNumber & hasUpper) {
			let score++;
		}

		// Increases the score if the password contains numbers, upper and lower case letters
		if preg_match("![^0-9a-zA-Z]!", password) {
			let score++;
		}

		// Increases the score if the password contains special characters
		if preg_match("![^\w\s]!", password) {
			let score++;
		}

		// The maximum score at this step is 4 (password with numbers, special characters, upper and lower case letters)

		let passwordLength = mb_strlen(password);

		// If the password exceeds the length of 16 adds 2 to the score,
		// Otherwise, if it exceeds 8, it adds 1 to the score,
		// Otherwise, if its length is between 2 and 4 characters, decreases the score by 1,
		// Otherwise if the previous score is 0 and its length exceeds 0 characters, add 1 to the score
		if passwordLength >= 16 {

			let score += 2;

		} elseif passwordLength >= 8 {

			let score++;

		} elseif passwordLength <= 4 & score > 1 {

			let score--;

		} elseif passwordLength > 0 & score === 0 {

			let score++;
		}

		return score;
	}
}
