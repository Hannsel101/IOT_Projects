int photoStatusLED(uint8_t inputRead)
{
  if(inputRead > 600)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  return 0;
}
