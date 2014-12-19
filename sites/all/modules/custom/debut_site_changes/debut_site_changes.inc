<?php
/**
 *
 * @file
 *   Module logics.
 */

/**
 * Check if we need to update this node type.
 */
function debut_site_changes_update_check_type($type) {
  $values = variable_get('debut_site_changes_conf', array());
  $types = (isset($values['types']['node_types'])) ? $values['types']['node_types'] : '';

  return (!empty($types[$type])) ? TRUE : FALSE;
}

/**
 * Update statistics for given node.
 */
function debut_site_changes_update_stats($node) {

  // Get today's date.
  $time = strtotime(date('d-m-Y', time('now')));

  // Check if this node was update today already.
  $sid = db_select('debut_site_changes_stats', 'dscs')
    ->fields('dscs', array('sid'))
    ->condition('dscs.nid', $node->nid)
    ->condition('dscs.change_time', $time)
    ->execute()
    ->fetchField();

  // If node not updated today write stats.
  if (empty($sid)) {
    $record = array(
      'nid' => $node->nid,
      'change_time'  => $time,
    );

   drupal_write_record('debut_site_changes_stats', $record);
  }

  return;
}

/**
 * Get stats info.
 */
function debut_site_changes_get_stats($start_time) {
  if (empty($start_time)) {
    $start_time = strtotime(date("d-m-Y", strtotime(date('m') . '/01/' . date('Y') . ' 00:00:00')));
  }

  $end_time = strtotime(date("d-m-Y", strtotime('-1 second', strtotime('+1 month', strtotime(date('m') . '/01/' . date('Y') . ' 00:00:00')))));

  // Get changes for asked period.
  $query = db_select('debut_site_changes_stats', 'dscs');
  $query->innerJoin('node', 'n', 'dscs.nid = n.nid AND n.status = 1');
  $query->fields('dscs', array('sid'));
  $query->fields('dscs', array('nid'));
  $query->fields('dscs', array('change_time'));
  $query->fields('n', array('type'));
  $query->condition('dscs.change_time', array($start_time, $end_time), 'BETWEEN');
  $nodes = $query->execute();

  $result = array();

  foreach ($nodes as $node) {
    $result[$node->sid] = array(
      'date' => array(date('m', $node->change_time), date('d', $node->change_time), date('Y', $node->change_time)),
      'type' => $node->type,
      'nid' => $node->nid,
    );
  }

  return $result;
}

/**
 * Get stats info for given date.
 */
function debut_site_changes_get_stats_date($date = 'now') {

  $result = array();
  $date = strtotime(date('d-m-Y', strtotime($date)));

  // Get changes for current day.
  $query = db_select('debut_site_changes_stats', 'dscs');
  $query->innerJoin('node', 'n', 'dscs.nid = n.nid AND n.status = 1');
  $query->fields('dscs', array('sid'));
  $query->fields('dscs', array('nid'));
  $query->fields('dscs', array('change_time'));
  $query->fields('n', array('type'));
  $query->condition('dscs.change_time', $date);
  $nodes = $query->execute();

  $result = array();

  foreach ($nodes as $node) {
    $result[$node->sid] = array(
      'date' => date('m-d-Y',  $node->change_time),
      'type' => $node->type,
      'nid' => $node->nid,
    );
  }

  return $result;
}
