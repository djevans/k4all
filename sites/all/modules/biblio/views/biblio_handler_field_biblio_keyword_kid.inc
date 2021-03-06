<?php
// $Id: biblio_handler_field_biblio_keyword_kid.inc,v 1.1.2.2 2009/06/05 21:12:52 rjerome Exp $

class biblio_handler_field_biblio_keyword_kid extends views_handler_field_prerender_list {
  function init(&$view, $options) {
    parent::init($view, $options);
    if ($view->base_table == 'node_revisions') {
      $this->additional_fields['vid'] = array('table' => 'node_revisions', 'field' => 'vid');
    }
    else {
      $this->additional_fields['vid'] = array('table' => 'node', 'field' => 'vid');
    }
  }


  function pre_render($values) {
    $this->field_alias = $this->aliases['vid'];
    $vids = array();
    foreach ($values as $result) {
      if (!empty($result->{$this->aliases['vid']})) {
        $vids[] = $result->{$this->aliases['vid']};
      }
    }
    if ($vids) {

      $result = db_query("SELECT bk.vid AS node_vid, bkd.* FROM {biblio_keyword_data} bkd INNER JOIN {biblio_keyword} bk ON bkd.kid = bk.kid WHERE bk.vid IN (" . implode(', ', $vids) . ") ORDER BY  bkd.word");

      while ($term = db_fetch_object($result)) {
//        if (empty($this->options['link_to_taxonomy'])) {
          $this->items[$term->node_vid][$term->kid] = check_plain($term->word);
//        }
//        else {
//          $this->items[$term->node_vid][$term->kid] = l($term->word, taxonomy_term_path($term));
//        }
      }
    }
  }
}
