<?php
/**
 * @file
 * Migration classes.
 */

 class DebutNewsMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the news nodes from old version');

    // Define the field which normally is a primary key
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Grab data from tables in source database
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
          ->fields('n', array('nid', 'vid', 'title', 'uid', 'status'))
          ->condition('n.type', 'news', '=');
    $query->join(SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('nr', array('body'));

    // Grab other fields which can mapping directly
    $query->join(SOURCE_DATABASE . '.content_type_news', 'ct', 'ct.vid = n.vid');
    $query->addField('ct', 'field_news_annonce_value');
    $query->join(SOURCE_DATABASE . '.content_field_publication_date', 'cf', 'cf.vid = n.vid');
    $query->addField('cf', 'field_publication_date_value');
    $query->orderBy('n.nid', 'ASC');

    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'nid' => t('Node id'),
      'title' => t('Node title'),
    );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('news');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name
    $this->addSimpleMappings(array('title', 'nid', 'status'));
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('field_news_annonce', 'field_news_annonce_value');
    $this->addFieldMapping('field_news_full_text', 'body');
    $this->addFieldMapping('field_publication_date', 'field_publication_date_value');

  }

}
