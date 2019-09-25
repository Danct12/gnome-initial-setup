static void
passcode_entry_text_inserted_cb (GisPage     *self,
                                 gchar       *new_text,
                                 gint         new_text_length,
                                 gpointer     position,
                                 GtkEditable *editable)
{
  size_t len, digit_end;

  g_assert (GIS_IS_PAGE (self));
  g_assert (GTK_IS_WIDGET (editable));

  if (!new_text || !*new_text)
    return;

  if (new_text_length == -1)
    len = strlen (new_text);
  else
    len = new_text_length;

  digit_end = strspn (new_text, "1234567890");

  /* User inserted only numbers */
  if (digit_end == len)
    return;

  /* Stop ::insert-text emission so that the text
   * won't be inserted into the entry */
  g_signal_stop_emission_by_name (editable, "insert-text");
  gtk_widget_error_bell (GTK_WIDGET (editable));
}
