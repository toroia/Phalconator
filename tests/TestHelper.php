<?php

// Define ROOTPATH constant
define('ROOTPATH', dirname(__DIR__));

// Error detection
ini_set("display_errors", 1);
error_reporting(E_ALL);

// Import composer autoloader
include ROOTPATH . "/vendor/autoload.php";
