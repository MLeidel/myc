<?php

function getKeyShift($inx) {
    $skey = "";
    $ck1 = "";
    $ck1n = 0;
    $skey = strval($inx); // make string of the int key code
    $ck1 = $skey[1];      // take 2nd digit of the (numeric) string
    $ck1n = intval($ck1);   // convert and return as int
    if ($ck1n == 0) $ck1n = 3;   // many zeros with no shift value
    return $ck1n; 
}

// INPUTS
$plaintext = "convert and return";
$ckey = "heLLo";

// GLOBAL VARS
$kix = 0;
$klen = strlen($ckey);
$cryptext = ""; // holds output string

// action "e" for encrypt
for($chr=0; $chr < strlen($plaintext); $chr++) {
    $cval = $chr + getKeyShift($kix);
    // putc(cval, f_out);
    $cryptext .= $cval;
    $kix++;
    if ($kix > $klen) $kix = 0;
}

echo $cryptext;
