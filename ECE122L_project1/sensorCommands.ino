int photoStatusLED(uint8_t inputRead)//did not work digitalWrite?
{
  if(inputRead > 600)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  return 0;
}
