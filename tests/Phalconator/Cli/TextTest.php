<?php

namespace Tests\Phalconator\Cli;

use Phalconator\Cli\Text;
use PHPUnit\Framework\TestCase;

class TextTest extends TestCase
{
    public function testColor()
    {
        $data = 'lorem ipsum';

        $text = new Text($data);
        $text->colorize('red');

        $this->assertNotEquals(strlen($data), strlen($text));
    }
}
