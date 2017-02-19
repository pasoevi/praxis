function encrypt($text, $n) {
  if (empty($text) || $n <= 0) {
    return $text;
  }
  
  $result = '';
  
  for ($i = 1; $i <= strlen($text); $i += 2) {
    $result .= $text[$i];
  }
  
  for ($i = 0; $i <= strlen($text); $i += 2) {
    $result .= $text[$i];
  }
  
  return encrypt($result, $n - 1);
  
}

function decrypt($text, $n) {

}